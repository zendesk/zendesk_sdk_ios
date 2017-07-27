/*
 *
 *  ZDKArticleViewController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 24/09/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>

#import "ZDKUIViewController.h"
#import "ZDKArticleView.h"
#import <ZendeskProviderSDK/ZDKHelpCenterConversationsUIDelegate.h>
#import <MessageUI/MessageUI.h>


@class ZDKArticleView, ZDKHelpCenterArticle, ZDKHelpCenterArticleViewModel;

/**
 *  View controller for an article view.
 *
 *  @since 0.9.3.1
 */
@interface ZDKArticleViewController : ZDKUIViewController<MFMailComposeViewControllerDelegate, ZDKHelpCentreArticleViewProtocol>


/**
 *  Delegate for right nav bar button.   
 *
 *  @since 1.10.0.1
 */
@property (nonatomic, weak) id<ZDKHelpCenterConversationsUIDelegate> uiDelegate;

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

/**
 *  Initializes the article controller with an article view model which trigger a network call
 *  to fetch the full article model.
 *
 *  @param articleViewModel An articleViewModel
 *
 *  @since 1.7.0.1
 */
- (instancetype) initWithArticleViewModel:(ZDKHelpCenterArticleViewModel *)articleViewModel;

@end
