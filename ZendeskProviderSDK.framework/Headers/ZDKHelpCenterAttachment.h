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

/**
 *  A model for Help Center Attachments.
 *
 *  @since 0.9.3.1
 */
@interface ZDKHelpCenterAttachment : NSObject

/**
 *  The id of an attachment.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *sid;

/**
 *  The url where the attachment can be found.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *url;

/**
 *  The id of the article for which an attachment belongs.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *article_id;

/**
 *  The file name of an attachment.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *file_name;

/**
 *  Content url for an attachment.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *content_url;

/**
 *  The MIME type for an attachment.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *content_type;

/**
 *  Attachment file size.
 *
 *  @since 0.9.3.1
 */
@property (assign, nonatomic) NSUInteger size;

/**
 *  Is this an inline attachment?
 *
 *  @since 0.9.3.1
 */
@property (assign, nonatomic) BOOL isInline;


/**
 *  Parses a single Help Center json attachment object.
 *
 *  @since 0.9.3.1
 *
 *  @return A new ZDKHelpCenterAttachment.
 */
+ (ZDKHelpCenterAttachment *) parseAttachment:(NSDictionary *)attachmentJson;


/**
 *  Parses a collection of Help Center json attachments objects.
 *
 *  @since 0.9.3.1
 *
 *  @param json JSON representation of attachments.
 *
 *  @return An array of Help Center attachment models.
 */
+ (NSArray *) parseAttachments:(NSDictionary *)json;


/**
 *  Returns a string human readable format of file size.
 *
 *  @since 0.9.3.1
 *
 *  @return human readable format of the file size.
 */
- (NSString *) humanReadableFileSize;


@end
