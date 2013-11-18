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

static inline NSString* RMLocalizedStringForKeyInBundle(NSString *key, NSBundle *bundle)
{
	NSString *string = [bundle localizedStringForKey:key value:@"" table:nil];
	
	if ([string isEqualToString:key])
	{
		string = [[NSBundle mainBundle] localizedStringForKey:key value:@"" table:nil];
	}
	
	return string;
}

#define RMLocalizedStringInSelfBundle(key) (RMLocalizedStringForKeyInBundle(key, RMSelfBundle()))

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

//***************************************************************************

#if !defined(__has_feature)
#define __has_feature(x) 0
#endif /* !defined(__has_feature) */

/// Cast a CFTypeRef (Core Foundation object) to an id (NSObject)
static inline id NSCFCast(CFTypeRef const CFObject)
{
#if __has_feature(objc_arc)
	return (__bridge id)CFObject;
#else
	union _ { CFTypeRef CFTypedObject; id NSTypedObject; };
	return ((union _*)&CFObject)->NSTypedObject;
#endif /* __has_feature(objc_arc) */
}

/// Cast an id (NSObject) to a CFTypeRef (Core Foundation object)
static inline CFTypeRef CFNSCast(id object)
{
#if __has_feature(objc_arc)
	return (__bridge CFTypeRef)object;
#else
	union _ { CFTypeRef CFTypedObject; id NSTypedObject; };
	return ((union _*)&object)->CFTypedObject;
#endif /* __has_feature(objc_arc) */
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
	NSFileManager *manager = [[NSFileManager alloc] init];
#if __has_feature(objc_arc)
	return manager;
#else
	return [manager autorelease];
#endif /* __has_feature(objc_arc) */
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
