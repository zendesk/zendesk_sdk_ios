/*
 *
 *  ZDKSupportViewController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 10/09/2014.  
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
#import "ZDKHelpCenterConversationsUIDelegate.h"

@class ZDKSupportView, ZDKHelpCenterCategory, ZDKHelpCenterSection;



@interface ZDKSupportViewController : ZDKUIViewController <UIScrollViewDelegate, UISearchBarDelegate>


/**
 * The support view that displays help center content.
 */
@property (nonatomic, strong) ZDKSupportView *supportView;

/**
 *  Delegate for nav ban button UI. 
 */
@property (nonatomic, weak) id<ZDKHelpCenterConversationsUIDelegate> delegate;


/**
 * Initializes the support controller with the list of categories in help center.
 */
- (instancetype) init;

/**
 * Initializes the support view controller with the list of articles specifed in labels argument
 *
 * @param labels An array of article label_names. The articles associated with these labels will be shown
 */
- (instancetype) initWithLabels:(NSArray *)labels;


/**
 * Initializes the support controller with the list of sections in the given category.
 *
 * @param category A help center category. The sections in this category will be loaded in the view.
 */
- (instancetype) initWithCategory:(ZDKHelpCenterCategory *)category;


/**
 * Initializes the support controller with the list of articles in the given section.
 *
 * @param section A help center section. The articles in this section will be loaded in the view.
 */
- (instancetype) initWithSection:(ZDKHelpCenterSection *)section;


/**
 *  Dismiss modally presented controller.
 *
 *  @since 1.4.1.1
 */
- (void) dismiss;

@end
