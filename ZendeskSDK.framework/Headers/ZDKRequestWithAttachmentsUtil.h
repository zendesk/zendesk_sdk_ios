/*
 *
 *  ZDKRequestWithAttachmentsUtil.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 1/26/15.
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
#import "ZDKUploadProvider.h"
#import "ZDKRequestProvider.h"

@class ZDKComment, ZDKRequest;


@interface ZDKRequestWithAttachmentsUtil : NSObject


- (void) uploadAttachment:(NSData*)data
             withFilename:(NSString*)filename
           andContentType:(NSString*)contentType
                 callback:(ZDKUploadCallback)callback;


- (void) createRequest:(ZDKRequest*)request
              withTags:(NSArray*)tags
           andCallback:(ZDKCreateRequestCallback)callback;

- (void) deleteFilename:(NSString*)filename;



- (void)addComment:(ZDKComment *)comment
      forRequestId:(NSString *)requestId
      withCallback:(ZDKRequestAddCommentCallback)callback;



- (NSString *) MIMETypeForData:(NSData*)data;


@end
