/*
 *
 *  ZDKAttachmentProvider.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 13/01/2015.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 * By dowloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 * of Service ( https://www.zendesk.com/company/terms ) and Application Developer and API License
 * Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 * acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKUploadResponse.h"


typedef void (^ZDKUploadCallback)(ZDKUploadResponse *uploadResponse, NSError *error);

typedef void (^ZDKDeleteUploadCallback)(NSString *responseCode, NSError *error);


@interface ZDKUploadProvider : NSObject

/**
 *  Upload an image to Zendesk, returns a token in the response that can be used to attach the file to a request
 *
 *  @param attachment    The attachment to upload
 *  @param filename      The file name you wan't to store the image as.
 *  @param contentType   The content type of the data, i.e: "image/png".
 *  @param callback      Block callback executed on request error or success.
 */
- (void) uploadAttachment:(NSData *)attachment
             withFilename:(NSString *)filename
           andContentType:(NSString*)contentType
                 callback:(ZDKUploadCallback)callback;


/**
 *  Delete an upload from Zendesk. Will only work if the upload has not been associated with a request/ticket.
 *
 *  @param uploadToken Upload token of file to delete
 *  @param callback    Block callback executed on request error or success. Can be nil.
 */
- (void) deleteUpload:(NSString*)uploadToken
          andCallback:(ZDKDeleteUploadCallback)callback;


@end
