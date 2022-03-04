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

#import <RWKit/RWKit-Constants.h>

#pragma mark - RapidWeaver API

#import <RWKit/RWDocumentProtocol.h>
#import <RWKit/RWPageProtocol.h>
#import <RWKit/RWResourceProtocol.h>

#pragma mark - Plugin API

#import <RWKit/RWPluginProtocol.h>
#import <RWKit/RWPluginArchivingProtocol.h>
#import <RWKit/RWPluginEditingProtocol.h>
#import <RWKit/RWPluginEditingViewControllersProtocol.h>
#import <RWKit/RWPluginExportProtocol.h>
#import <RWKit/RWPluginHealthCheckProtocol.h>
#import <RWKit/RWPluginMetadataProtocol.h>
#import <RWKit/RWPluginSearchProtocol.h>
#import <RWKit/RWSearchContextProtocol.h>
#import <RWKit/RWSearchResultProtocol.h>
#import <RWKit/RWSharedPluginDataProtocol.h>
#import <RWKit/RWSharedPluginDataMigrationProtocol.h>

#pragma mark - Plugin Classes

#import <RWKit/RWAbstractPlugin.h>
#import <RWKit/RWTextViewPluginClient.h>

#pragma mark - Export

#import <RWKit/RWExportParams.h>
#import <RWKit/RMHTML.h>

#pragma mark - Views

#import <RWKit/RWCodeView.h>
#import <RWKit/RWTextView.h>
#import <RWKit/RWStyledTextView.h>
#import <RWKit/RWTextAttachment.h>
#import <RWKit/RWTextAttachmentCellWrapper.h>

#pragma mark - Styled Text

#import <RWKit/RWStyledText.h>

#pragma mark - Links

#import <RWKit/RWLink.h>
#import <RWKit/RWLinkPanel.h>

#pragma mark - EXPORT (RW9 only)

#import <RWKit/RWPluginPublishingProtocol.h>
