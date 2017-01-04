/*
 *
 *  ZDKHelpCenterSearchResultCell.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 15/09/2014.  
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
#import "ZDKSupportTableViewCell.h"

@interface ZDKSupportArticleTableViewCell : UITableViewCell <UIAppearanceContainer>

#pragma mark - Properties

/**
 * A label which displays the articles parent category and section.
 *
 */
@property (nonatomic, strong, readonly) UILabel *articleParents;

/**
 * A label which displays the articles title.
 *
 */
@property (nonatomic, strong, readonly) UILabel *title;

#pragma mark - Methods

/**
 * Helper method calculates the height of the cell for the given width.
 *
 * @param width The width to use in the cell height calculation.
 */
- (CGFloat) cellHeightForWidth:(CGFloat)width;

/**
 * Helper method to retrieve this classes cell identifier.
 *
 * @returns The classes cell identifier.
 */
+ (NSString *) cellIdentifier;

@end
