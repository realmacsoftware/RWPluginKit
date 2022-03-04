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


/// Public API for a RapidWeaver Resource
/// A resource can be a folder, remote url, file stored within the document or something else
@protocol RWResourceProtocol

/// The identifier that uniquely identifies this resource
@property (nonatomic, readonly) NSString * _Nonnull identifier;

/// Returns an array of all direct child resources
@property (nonatomic, readonly) NSArray <id <RWResourceProtocol>> * _Nullable items;

/// Returns the file or folder name of this resource
@property (nonatomic, readonly) NSString * _Nullable name;

/// Returns YES if the resource is a URL pointing to a remote resource
@property (nonatomic, readonly) BOOL isRemoteResource;

/// Returns YES if the resource is a file stored within the document
@property (nonatomic, readonly) BOOL isDocumentResource;

/// Returns YES if the resource is a folder containing other resources
@property (nonatomic, readonly) BOOL isFolder;

/// Returns a file wrapper for this resource if it's a document resource
@property (nonatomic, readonly) NSFileWrapper * _Nullable wrapper;

/// Returns the published URL of this resource.
@property (nonatomic, readonly) NSURL * _Nullable publishedURL;

/// Returns the macroString for this resource.
@property (nonatomic, readonly) NSString * _Nullable macroString;

/// Returns an image sutable for displaying within RapidWeaver
@property (nonatomic, readonly) NSImage * _Nullable previewImage;

/// Returns a cg image source pointing to the original image files
@property (nonatomic, readonly) id _Nullable cgImageSourceRef;

/// Create a child resource for the given url. If the resource exists the user will be asked if they'd like to duplicate the resource. This method will only succeed if this resource is a folder.
- (id <RWResourceProtocol> _Nullable)addResourceWithURL:(NSURL * _Nonnull)url error:(NSError * _Nullable * _Nullable)error;

/// Create a child resource for the given FileWrapper. This method will only succeed if this resource is a folder.
- (id <RWResourceProtocol> _Nullable)addResourceWithWrapper:(NSFileWrapper * _Nonnull)wrapper error:(NSError * _Nullable * _Nullable)error;

/// Create a child resource for the given file promise. This method will only succeed if this resource is a folder.
- (id <RWResourceProtocol> _Nullable)addResourceWithFilePromise:(NSFilePromiseReceiver * _Nonnull)promise error:(NSError * _Nullable * _Nullable)error;

/// Adds a child folder with the given name. If a folder already exists with the same name, a unique number will be appended. This method will only succeed if this resource is a folder.
- (id <RWResourceProtocol> _Nullable)addFolderResourceNamed:(NSString * _Nonnull)folderName error:(NSError * _Nullable * _Nullable)error;

@end
