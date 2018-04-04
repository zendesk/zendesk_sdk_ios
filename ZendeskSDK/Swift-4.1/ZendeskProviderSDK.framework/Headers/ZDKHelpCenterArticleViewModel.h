/*
 *
 *  ZDKHelpCenterArticleViewModel.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 11/05/2016.
 *
 *  Copyright © 2016 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKHelpCenterViewModel.h"

@interface ZDKHelpCenterArticleViewModel : NSObject <ZDKHelpCenterViewModel>

/**
 *  Article id.
 *
 *  @since 1.7.0.1
 */
@property (nonatomic, copy) NSString *articleId;

/**
 *  Section id.
 *
 *  @since 1.7.0.1
 */
@property (nonatomic, copy) NSString *sectionId;

/**
 *  Article title.
 *
 *  @since 1.7.0.1
 */
@property (nonatomic, copy) NSString *title;

/**
 *  Parses returned json to articles
 *
 *  @param json The Json to be parsed
 *
 *  @return An array of help center articles
 */
+ (NSArray<ZDKHelpCenterArticleViewModel *> *)parseArticles:(NSDictionary *)json;

/**
 *  Parses json to a single article
 *
 *  @param json The json to be parsed
 *
 *  @return a basic article
 */
+ (ZDKHelpCenterArticleViewModel *)parseArticle:(NSDictionary *)json;

@end
