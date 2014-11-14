//
//  ZDKHelpCenterAttachmentsDataSource.h
//  ZendeskSDK
//
//  Created by Zendesk on 07/11/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <ZendeskSDK/ZendeskSDK.h>

@interface ZDKHelpCenterAttachmentsDataSource : ZDKHelpCenterDataSource

/**
 * Initializes a data source with a cell identifire, configuration block and a provider.
 * @param articleId The articleId passed as a String, the article to which attachments will be fetched
 */

- (instancetype) initWithArticleId:(NSString *)articleId ;

@end
