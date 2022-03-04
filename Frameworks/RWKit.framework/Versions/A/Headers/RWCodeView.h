//************************************************************************
//
//  RapidWeaver Plugin Development Kit
//  Copyright © 2022 Realmac Software. All rights reserved.
//
//  These coded instructions, statements, and computer programs contain
//  unpublished proprietary information of Realmac Software Ltd
//  and are protected by copyright law. They may not be disclosed
//  to third parties or copied or duplicated in any form, in whole or
//  in part, without the prior written consent of Realmac Software Ltd.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
//  ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
//  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE
//
//************************************************************************

@import Cocoa;

extern NSString * const RWCodeHighlightingLanguageHTML;
extern NSString * const RWCodeHighlightingLanguageCSS;
extern NSString * const RWCodeHighlightingLanguagePHP;
extern NSString * const RWCodeHighlightingLanguageJavascript;
extern NSString * const RWCodeHighlightingLanguageMarkdown;

@interface RWCodeView : NSView

@property (nonatomic, strong) NSString *string;
@property (nonatomic, readonly) NSTextView *textView;

@property (nonatomic, weak) IBOutlet id <NSTextViewDelegate> delegate;

@property (nonatomic, assign) BOOL showLineNumbers;
@property (nonatomic, strong) NSString *language;
@property (nonatomic, assign) BOOL hasBorder;
@property (nonatomic, assign) BOOL editable;
@property (nonatomic, assign) CGFloat fontSize;

@end
