/*
 *
 *  ZDKArticleView.h
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
#import "ZDKSpinnerDelegate.h"

@class ZDKHelpCenterArticle;

@protocol ZDKHelpCentreArticleViewProtocol <NSObject>

@optional
/**
 *  This is delegate method called by the ZDKArticleViewController, it is
 *  for linking within app to a mail composer view when an email prependded
 *  with a "mailto:" tag within a help center article is tapped.
 *  It sets the email as the receiver.  If the device, does not have
 *  email set up, an actionSheet will be shown and the mail comnposer
 *  will not be.
 *
 *  @param reciever The email that will be set as the receiver in mail composer view.
 *
 *  @since 1.5.0.1
 */
- (void)openMailWithReciever:(NSString *)reciever;

/**
 *  This is a delegate method for linking within app to another help center article.
 *  It called when an article link is clicked within an ZDKArticleView.  It is called by
 *  recognising the host-mapped URL of the account and other path components within
 *  that URL to recognise it as a help center article.  This is done in a different method
 *  within the ZDKArticleView.
 *
 *  @param articleId This articleId is the ID of the help center article, which the user 
 *  wants to deeplink to within the SDK.
 *
 *  @since 1.5.0.1
 */
- (void)openLinkToNewArticle:(NSString *)articleId;

@end



/**
 *  A Help Center Article.
 *
 *  @since 0.9.3.1
 */
@interface ZDKArticleView : UIView <UIAppearanceContainer>

/**
 *  Delegate for ZDKHelpArticleViewProtocol.
 *
 *  @since 1.5.0.1
 */
@property (nonatomic, weak) id<ZDKHelpCentreArticleViewProtocol> delegate;


/**
 * Scroll view that contains the article webview and attachments table.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, strong) UIScrollView *article;

/**
 * The article body.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, strong) UIWebView *articleWebView;


/**
 * A table for article attachments.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, strong) UITableView *attachments;


/**
 *  Returns the loading state of the article view.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, assign, readonly, getter=isLoading) BOOL loading;


/**
 * Initializes the article controller with an article.
 *
 *  @since 0.9.3.1
 *
 * @param article A help center article.
 */
- (instancetype) initWithArticle:(ZDKHelpCenterArticle *)article;

/**
 *  Returns an article View with a loading state
 *
 *  @since 1.7.0.1
 */
+ (instancetype) loadingArticle;

/**
 *  Renders the article passed into it in the view.
 *
 *  @param article A help center article
 *
 *  @since 1.7.0.1
 */
- (void)renderArticle:(ZDKHelpCenterArticle *)article;

/**
 * Reloads the help center article webview on rotation.
 *
 *  @since 0.9.3.1
 *
 */
- (void) reloadArticleForRotation;

/**
 *  Loading spinner for article deeplinking.
 *
 *  @since 1.5.0.1
 */
@property (nonatomic, strong) UIActivityIndicatorView *deeplinkingSpinner;

@end
