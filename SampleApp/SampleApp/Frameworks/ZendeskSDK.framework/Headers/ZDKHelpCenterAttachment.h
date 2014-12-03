/*
 *
 *  ZDKHelpCenterAttachment.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 25/09/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>

@interface ZDKHelpCenterAttachment : NSObject

@property (strong, nonatomic) NSString *sid;
@property (strong, nonatomic) NSString *url;
@property (strong, nonatomic) NSString *article_id;
@property (strong, nonatomic) NSString *file_name;
@property (strong, nonatomic) NSString *content_url;
@property (strong, nonatomic) NSString *content_type;
@property (assign, nonatomic) NSUInteger size;
@property (assign, nonatomic) BOOL isInline;


/**
 * Parses a single Help Center json attachment object.
 *
 * @return A new ZDKHelpCenterAttachment.
 */
+ (ZDKHelpCenterAttachment *) parseAttachment:(NSDictionary *)attachmentJson;


/**
 * Parses a collection of Help Center json attachments objects
 *
 */
+ (NSArray *) parseAttachments:(NSDictionary *)json;

/**
 *  Returns a string human readable format of file size
 *
 *  @return human readable format of the file size
 */
- (NSString *) humanReadableFileSize;

@end
