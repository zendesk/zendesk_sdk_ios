//
//  ZDKHelpCenterSearchResultCell.h
//  ZendeskSDK
//
//  Created by Zendesk on 15/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ZDKHelpCenterSearchResultCell : UITableViewCell

/**
 * A label which displays the articles parent category and section.
 *
 */
@property (nonatomic, strong) UILabel *articleParents;

/**
 * A label which displays the articles title.
 *
 */
@property (nonatomic, strong) UILabel *title;


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
