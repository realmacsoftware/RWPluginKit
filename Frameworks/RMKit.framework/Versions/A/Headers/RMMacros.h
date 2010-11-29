//***************************************************************************

// Copyright (C) 2007 Realmac Software Pty Ltd
// 
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject
// to the following conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
// CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

//***************************************************************************

#pragma once

#define RM_NORETURN __attribute__((noreturn))

#define RM_SETS_NSERROR

/// This is a simple addition to the normal NSLog() function that also outputs the current function/method name, and the current filename and line number.
#define RMLog(format, ...) { NSLog(@"%s (%@:%u): " format, __func__, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, ## __VA_ARGS__); };

/// This macro is used to verify that an arbitrary expression is true.  
/** This macro's intention is similar to assert() and NSCAssert(), except that an expression that fails verification is not regarded as fatal.  Instead of throwing an exception or calling abort(), an unverified expression will (1) emit a warning on the console, and (2) break into the debugger if one is attached.  This macro evalutes to YES or NO depending on whether the expression passed to is true or false, and should be safe to use inside if() conditional checks.  The expression passed to this macro is guaranteed to only be evaluated once. */
#define RMVerifyExpression(expression) \
	( \
		(expression) \
		? \
			YES \
		: \
		( \
			NSLog(@"warning: RMVerifyExpression failed check for `%s' in %s (%s:%d), breaking into debugger if one is attached.", #expression, __func__, __FILE__, __LINE__), \
			Debugger(), \
			NO \
		) \
	)

/// This macro is used as a "safe cast" for Objective-C objects; e.g.  (NSMutableString, myString);
/** Pass in the classname and the object to be casted.  If the object returns YES to -isKindOfClass: for the given class name, a pointer casted to the object's typed will be returned.  Otherwise, an RMVerifyExpression() failure will occur and nil will be returned. */
#define RMObjectCast(className, expression) \
	( \
		([(id)(expression) isKindOfClass:[className class]]) \
		? \
			((className*)(expression)) \
		: \
			(nil) \
	)

/// This macro is used as a "safe cast" for Objective-C objects; e.g. RMProtocolCast(NSCoding, myObject);
/** Pass in the protocol name and the object to be casted.  If the object returns YES to -conformsToProtocol: for the given protocol name, a pointer casted to the object's typed will be returned.  Otherwise, an RMVerifyExpression() failure will occur and nil will be returned. */
#define RMProtocolCast(protocolName, expression) \
	( \
			([(id)(expression) conformsToProtocol:@protocol(protocolName)]) \
		? \
			((id<protocolName>)(expression)) \
		: \
			(nil) \
	)

/// A shortcut for [NSBundle bundleForClass:[self class]]
#define RMSelfBundle() ([NSBundle bundleForClass:[self class]])

/// Invokes -localizedStringForKey:value:table on the bundle for the current class, with an empty string for the value (@"") and a nil table.  e.g. RMLocalizedStringInSelfBundle(@"Foo")
#define RMLocalizedStringInSelfBundle(key) ([RMSelfBundle() localizedStringForKey:(key) value:@"" table:nil])

//***************************************************************************

// Common Objective-C object constructors, to ease the pain.

/// A convenience macro for [NSArray arrayWithObjects:..., nil];
#define NSArrayMake(x...) [NSArray arrayWithObjects:x, nil]

/// A convenience macro for [NSMutableArray arrayWithObjects:..., nil];
#define NSMutableArrayMake(x...) [NSMutableArray arrayWithObjects:x, nil]

/// A convenience macro for [NSDictionary dictionaryWithObjectsAndKeys:..., nil];
#define NSDictionaryMake(x...) [NSDictionary dictionaryWithObjectsAndKeys:x, nil]

/// A convenience macro for [NSMutableDictionary dictionaryWithObjectsAndKeys:..., nil];
#define NSMutableDictionaryMake(x...) [NSMutableDictionary dictionaryWithObjectsAndKeys:x, nil]

/// A convenience macro for [NSArray arrayWithObjects:..., nil];
#define NSMakeArray(x...) NSArrayMake(x)

/// A convenience macro for [NSMutableArray arrayWithObjects:..., nil];
#define NSMakeMutableArray(x...) NSMutableArrayMake(x)

/// A convenience macro for [NSDictionary dictionaryWithObjectsAndKeys:..., nil];
#define NSMakeDictionary(x...) NSDictionaryMake(x)

/// A convenience macro for [NSMutableDictionary dictionaryWithObjectsAndKeys:..., nil];
#define NSMakeMutableDictionary(x...) NSMutableDictionaryMake(x)

/// Similar to kCFBooleanTrue, but returns an NSNumber* instead
#define NSNumberYES ((NSNumber*)kCFBooleanTrue)

/// Similar to kCFBooleanFalse, but returns an NSNumber* instead
#define NSNumberNO ((NSNumber*)kCFBooleanFalse)

//***************************************************************************

static inline void CFRetainIvar(void* const pIVar, CFTypeRef value)
{
	// Note: The first parameter needs to be a void* rather than CFTypeRef*, otherwise we'll get a warning when trying to pass pointers to e.g. a CGImageRef
	
	CFTypeRef* const pCFIvar = (CFTypeRef* const)pIVar;
	
	if(*pCFIvar == value) return;
	
	if(*pCFIvar != NULL) CFRelease(*pCFIvar);
	
	if(value == NULL) *pCFIvar = NULL;
	else *pCFIvar = CFRetain(value);
}

static inline void NSRetainIVar(id* const pIVar, id const value)
{
	if(*pIVar == value) return;
	
	[*pIVar release];
	*pIVar = [value retain];
}

//***************************************************************************

/// Cast a CFTypeRef (Core Foundation object) to an id (NSObject)
static inline id NSCFCast(CFTypeRef const CFObject)
{
	union _ { CFTypeRef CFTypedObject; id NSTypedObject; };
	return ((union _*)&CFObject)->NSTypedObject;
}

/// Cast an id (NSObject) to a CFTypeRef (Core Foundation object)
static inline CFTypeRef CFNSCast(id object)
{
	union _ { CFTypeRef CFTypedObject; id NSTypedObject; };

	return ((union _*)&object)->CFTypedObject;
}

//***************************************************************************

/// Adds the Core Foundation object to the autorelease pool under managed memory, or marks it as collectable under garbage collection.  Also see the SCOPED_CFRELEASE macro.
/** Note that CFAutorelease() has different semantics from SCOPED_CFRELEASE, which is why both exist.  Generally, SCOPED_CFRELEASE is more efficient and simpler and is the preferred option: however, it does not work in the case where a CFTypeRef variable is re-seated to point at different objects throughout its lifetime, nor does it work when the Core Foundation object needs to be returned from the called function.  CFAutorelease() will add it to the current NSAutoreleasePool and thus has exactly the same semantics as -autorelease, which all its advantages and disadvantages.  General rule of thumb: if you can declare your CFTypeRef as a const pointer, use SCOPED_CFRELEASE; if you cannot, use CFAutorelease(). */
#define CFAutorelease(cf) ((__typeof(cf))[NSMakeCollectable(cf) autorelease])

/// Similar to CFAutorelease(), but casts the resulting object to an id type.
/** Only do these for classes that are toll-free bridged, otherwise bad things will happen. */
static inline id NSCFAutorelease(CFTypeRef const cf)
{
	return [NSMakeCollectable(cf) autorelease];
}

/// Similar to CFRelease(), but won't crash if Core Foundation object passed to it is NULL.
static inline void CFSafeRelease(CFTypeRef const cf)
{
	if(cf) CFRelease(cf);
}

#define SCOPE_EXIT(function) __attribute__((cleanup(function)))

/// Put this macro before a local variable name (after its type declaration) to automatically CFSafeRelease() the Core Foundation object when it goes out of scope.  Note that this macro also declares the variable as const for safety reasons (since it can get confusing exactly which variable assignment gets released), and so must go before the variable name, not after the variable name.
/** e.g. CGImageRef SCOPED_CFRELEASE image = CGImageSourceCreateThumbnailAtIndex(imageSource, 0, NULL); */
#define SCOPED_CFRELEASE const SCOPE_EXIT(CFScopedRelease)

static inline void CFScopedRelease(const void* pCF)
{
	CFSafeRelease(*(CFTypeRef*)pCF);
}

//***************************************************************************

/// A shortcut function to avoid typing [NSApplication sharedApplication] all the time.
static inline NSApplication* TheApplication()
{
	return [NSApplication sharedApplication];
}

/// A shortcut function to avoid typing [[[NSFileManager alloc] init] autorelease] all the time.
/** We use alloc/init rather than +defaultManager because the former is thread-safe.  See <http://www.nabble.com/NSFileManager-and-thread-safety-td18070869.html> for more details, particularly the post by Bill Bumgarner. */
static inline NSFileManager* TheFileManager()
{
	return [[[NSFileManager alloc] init] autorelease];
}

/// A shortcut function to avoid typing [NSUserDefaults standardUserDefaults] all the time.
static inline NSUserDefaults* TheStandardUserDefaults()
{
	return [NSUserDefaults standardUserDefaults];
}

/// A shortcut function to avoid typing [NSDocumentController sharedDocumentController] all the time.
static inline NSDocumentController* TheDocumentController()
{
	return [NSDocumentController sharedDocumentController];
}

/// A shortcut function to avoid typing [NSNotificationCenter defaultCenter] all the time.
static inline NSNotificationCenter* TheNotificationCenter()
{
	return [NSNotificationCenter defaultCenter];
}

/// A shortcut function to avoid typing [NSProcessInfo processInfo] all the time.
static inline NSProcessInfo* TheProcessInfo()
{
	return [NSProcessInfo processInfo];
}

/// A shortcut function to avoid typing [NSGarbageCollector defaultCollector] all the time.
static inline NSGarbageCollector* TheGarbageCollector()
{
	return [NSGarbageCollector defaultCollector];
}

// A shortcut function to avoid typing [NSFontManager sharedFontManager] all the time.
static inline NSFontManager* TheFontManager()
{
	return [NSFontManager sharedFontManager];
}

// A shortcut function to avoid typing [NSColorPanel sharedColorPanel] all the time.
static inline NSColorPanel* TheColorPanel()
{
	return [NSColorPanel sharedColorPanel];
}

// A shortcut function to avoid typing [NSWorkspace sharedWorkspace] all the time.
static inline NSWorkspace* TheWorkspace()
{
	return [NSWorkspace sharedWorkspace];
}

// A shortcut function to avoid typing [NSBundle mainBundle] all the time.
static inline NSBundle* TheMainBundle()
{
	return [NSBundle mainBundle];
}

//***************************************************************************
