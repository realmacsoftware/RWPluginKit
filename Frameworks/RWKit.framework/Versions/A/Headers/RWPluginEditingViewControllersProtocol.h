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

/*
    New plugin API methods. We're moving to NSViewControllers, which means you'll receive more notifications about when your views are on screen.
    The below methods have been marked as optional, but it would make sense in most cases to return an NSViewController subclass from at least
    one of them.
    If your plugin does not implement -editingViewController, you will not appear in the page list.
 */

@protocol RWPluginEditingViewControllers <NSObject>

@optional
- (NSViewController * _Nonnull)editingViewController;
- (NSViewController * _Nullable)pageInspectorViewController;

/// If implemented, should return a view controller to be placed into the left side of the document window
/// Availability: RW9+
- (NSViewController * _Nullable)navigationViewController;

@end
