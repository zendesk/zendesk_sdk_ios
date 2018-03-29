/*
 *
 *  ZDKHelpCenterUi.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 15/03/2018.
 *
 *  Copyright (c) 2018 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */


@import UIKit;

#import "ZDKHelpCenterConversationsUIDelegate.h"

@class ZDKHelpCenterArticle;
@protocol ZDKUiConfiguration;

NS_ASSUME_NONNULL_BEGIN


@interface ZDKHelpCenterUi : NSObject

/**
 * Build the Help Center Overview view controller. Displays an overview of your HelpCenter
 *
 *  @since 2.0.0
 */
+ (UIViewController <ZDKHelpCenterDelegate>*) buildHelpCenterOverview;

/**
 * Build the Help Center Overview view controller with a list of ZDKUiConfigurations.
 *
 *  @param configs A list of ZDKUiConfigurations.
 *
 *  @since 2.0.0
 */
+ (UIViewController <ZDKHelpCenterDelegate>*) buildHelpCenterOverviewWithConfigs:(NSArray<ZDKUiConfiguration> *)configs;


/**
 * Build the Help Center Article view controller. Displays a single article.
 *
 *  @param article A ZDKHelpCenterArticle to display.
 *
 *  @since 2.0.0
 */
+ (UIViewController<ZDKHelpCenterDelegate>*) buildHelpCenterArticle:(ZDKHelpCenterArticle *)article;

/**
 * Build the Help Center Article view controller. Displays a single article.
 *
 *  @param article A ZDKHelpCenterArticle to display.
 *  @param configs A list of ZDKUiConfigurations.
 *
 *  @since 2.0.0
 */
+ (UIViewController<ZDKHelpCenterDelegate>*) buildHelpCenterArticle:(ZDKHelpCenterArticle *)article
                                                         andConfigs:(NSArray<ZDKUiConfiguration> *)configs;
/**
 * Build the Help Center Article view controller. Displays a single article.
 *
 *  @param articleId The ID of a Help Center article. This is fetched and displayed.
 *
 *  @since 2.0.0
 */
+ (UIViewController<ZDKHelpCenterDelegate>*) buildHelpCenterArticleWithArticleId:(NSInteger)articleId;

/**
 * Build the Help Center Article view controller. Displays a single article.
 *
 *  @param articleId The ID of a Help Center article. This is fetched and displayed.
 *  @param configs A list of ZDKUiConfigurations.
 *
 *  @since 2.0.0
 */
+ (UIViewController<ZDKHelpCenterDelegate>*) buildHelpCenterArticleWithArticleId:(NSInteger)articleId
                                                                      andConfigs:(NSArray<ZDKUiConfiguration> *)configs;


@end

NS_ASSUME_NONNULL_END
