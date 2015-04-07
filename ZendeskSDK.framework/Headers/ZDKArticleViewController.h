/*
 *
 *  ZDKArticleViewController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 24/09/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>

#import "ZDKUIViewController.h"

@class ZDKArticleView, ZDKHelpCenterArticle;


/**
 *  View controller for an article view.
 *
 *  @since 0.9.3.1
 */
@interface ZDKArticleViewController : ZDKUIViewController


/**
 * The article view.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, strong) ZDKArticleView *articleView;


/**
 * Initializes the article controller with an article.
 *
 *  @since 0.9.3.1
 *
 * @param article A help center article.
 */
- (instancetype) initWithArticle:(ZDKHelpCenterArticle *)article;


@end
