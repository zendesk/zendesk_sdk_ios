/*
 *
 *  ZDKHelpCenterAttachmentsDataSource.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 07/11/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import "ZDKHelpCenterDataSource.h"


/**
 *  Data source for Help Center attachments.
 *
 *  @since 0.9.3.1
 */
@interface ZDKHelpCenterAttachmentsDataSource : ZDKHelpCenterDataSource


/**
 *  Initializes a data source with a cell identifire, configuration block and a provider.
 *
 *  @since 0.9.3.1
 *
 *  @param articleId The articleId passed as a String, the article to which attachments will be fetched.
 *
 *  @return A new instance.
 */
- (instancetype) initWithArticleId:(NSString *)articleId ;


@end
