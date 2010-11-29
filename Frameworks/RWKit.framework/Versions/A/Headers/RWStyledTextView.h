//***************************************************************************

#import <Cocoa/Cocoa.h>

//***************************************************************************

@class RMHTMLPackage;
@class RWStyledText;
@class RWTextView;
@class RWWebEditView;
@class RWTextViewDefaultDelegate;

@protocol RWStyledTextViewDelegate;
@protocol RWPluginProtocol;
@protocol RWPage;

//***************************************************************************

// Implementation note: this enum is designed to be explicitly in sync with the NSTabView tab view item index number in the RWStyledTextView class.
typedef enum
{
	RWStyledTextViewModeAttributedString = 0,
	RWStyledTextViewModeHTML = 1,
}
RWStyledTextViewMode;

//***************************************************************************

@interface RWStyledTextView : NSView<NSCoding>
{
	NSTabView* _tabView;
	
	id _toolsViewController;
	
	RWTextView* _textView;
	RWWebEditView* _webView;
	
	RWStyledTextViewMode _styledTextMode;
	RWTextViewDefaultDelegate* _defaultTextViewDelegate;
	
	// Transient ivars
	// NSObject<RWStyledTextViewDelegate>* _delegate;
	id _delegate;
	
	/// We need this ivar because WebView's loading is asynchronous
	/** If a client demands an HTML package using -HTMLPackage after using -setHTMLPackage: but _before_ the WebView is finished loading, we return them this ivar rather than trying to create an RMHTMLPackage from the webView. */
	RMHTMLPackage* _HTMLPackageToLoad;
}

- (BOOL)isAttributedStringMode;
- (BOOL)isHTMLMode;

- (id<RWPluginProtocol>)plugin;

/// Sets up the WebView; this returns immediately if the WebView is already initialised and configured.
- (void)setupWebView;

// Actions
- (IBAction)onAddLink:(id)sender;
- (IBAction)onRemoveLink:(id)sender;
- (IBAction)onAction:(id)sender;
- (IBAction)onToggleSmartQuotes:(id)sender;
- (IBAction)onUnderline:(id)sender;
- (IBAction)onList:(id)sender;

// NSCoding
- (void)encodeWithCoder:(NSCoder*)aCoder;
- (id)initWithCoder:(NSCoder*)aDecoder;

@property RWStyledTextViewMode styledTextMode;

@property (copy) RWStyledText* styledText;

@property (readonly, retain) RWTextView* textView;

@property (copy) NSAttributedString* attributedString;

/// The WebView is initialised lazily because it can take a long time to initialise, which affects can significantly impact on nib loading time.  This property will return nil if the webView has not been initialised yet.  To force initialisation, call -setupWebView.
@property (readonly, retain) RWWebEditView* webView;

/// Returns the current text editing view, i.e. -textView if the receiver's styledTextMode is RWStyledTextViewModeAttributedString, or -webView if the receiver's styledTextMode is RWStyledTextViewModeHTML.
@property (readonly, retain) id textEditingView;

@property (copy) RMHTMLPackage* HTMLPackage;

/// The delegate for this styled text view.  Note that while the RWStyledTextView object will be the delegate set for the inner RWTextView, all of RWTextView's delegate messages will be forwarded to the main styled text view delegate object.
// @property (assign) NSObject<RWStyledTextViewDelegate>* delegate;
@property (assign) id delegate;

@property BOOL editable;

@end

//***************************************************************************

@protocol RWStyledTextViewDelegate <NSObject>

- (NSObject<RWPluginProtocol>*)pluginForStyledTextView:(RWStyledTextView*)styledTextView;

@optional

/// This delegate method is called when the RWStyledTextView changes modes.
/** The newMode parameter is the mode that the RWStyledTextView changed to; e.g. if it changed from Rich Text to HTML, newMode would be RWStyledTextViewModeHTML.  If the mode being changed to is HTML, this delegate method is called only when the HTML is fully loaded. */
- (void)styledTextView:(RWStyledTextView*)styledTextView didChangeMode:(RWStyledTextViewMode)newMode;

@end

//***************************************************************************

/// This notification name is posted when the RWStyledTextView changes modes.
/** If the mode being changed to is HTML, this notification is posted only when the HTML is fully loaded. */
extern NSString* const RWStyledTextViewDidChangeModeNotification;

//***************************************************************************

@interface RWTextViewDefaultDelegate : NSObject
{
	RWStyledTextView* _styledTextView;
	NSUndoManager* _undoManager;
}

+ (RWTextViewDefaultDelegate*)textViewDefaultDelegateWithStyledTextView:(RWStyledTextView*)styledTextView;

- (id)initWithStyledTextView:(RWStyledTextView*)styledTextView;

@property (assign) RWStyledTextView* styledTextView;

@end

//***************************************************************************
