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

@import Foundation;

/// To provide a search result to RapidWeaver you should add a class to your plugin that implements this protocol. Doing so allows you to add additional properties useful when navigating to a result
@protocol RWSearchResultProtocol

/// Used to provide more context to a search result - you can choose to show, for example, a few words before and after the search result.
/// We'll use this in the search window, and make the search query inside the string bold
@property (nonatomic, strong) NSString * _Nonnull surroundingText;

/// The range of this specific result in the surrounding text. If there are multiple instances of the search query in the surrounding text,
/// this is how we know which one to highlight.
@property (nonatomic, assign) NSRange rangeInSurroundingText;

/// Used for your reference, so you can navigate back to results if they're selected
@property (nonatomic, assign) NSRange range;

/// User info, if set during the search operation
@property (nonatomic, strong) id _Nullable userInfo;

@end
