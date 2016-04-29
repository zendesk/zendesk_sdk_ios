/*
 *
 *  ZDKRequestListTableCell.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 14/06/2014.  
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
#import "ZDKSpinnerDelegate.h"

@class ZDKRequest;

static CGFloat const ZDSDK_REQUEST_CELL_VERTICAL_MARGIN = 20.0f;
static CGFloat const ZDSDK_REQUEST_CELL_DESCRIPTION_TS_MARGIN = 5.0f;
static CGFloat const ZDSDK_REQUEST_CELL_LEFT_INSET = 25.0f;



/**
 * Request cell for the request list table.
 */
@interface ZDKRequestListTableCell : UITableViewCell

/**
 * The unread indicator view.
 */
@property (nonatomic, strong) UIView *unreadView;

/**
 * The description label.
 */
@property (nonatomic, strong) UILabel *requestDescription;

/**
 * 'The created at' label.
 */
@property (nonatomic, strong) UILabel *updatedAt;

/**
 * The font to be used by the description label.
 */
@property (nonatomic, strong) UIFont *descriptionFont __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * The font to be used by the created at label.
 */
@property (nonatomic, strong) UIFont *updatedAtFont __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * The color of the unread marker.
 */
@property (nonatomic, strong) UIColor *unreadColor UI_APPEARANCE_SELECTOR;

/**
 * The color of the description text.
 */
@property (nonatomic, strong) UIColor *descriptionColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * The color of the created at text.
 */
@property (nonatomic, strong) UIColor *updatedAtColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Vertical margin between the cell content and the cell edge.
 */
@property (nonatomic, strong) NSNumber *verticalMargin __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Vertical margin between the description text and the timestamp/created at text
 */
@property (nonatomic, strong) NSNumber *descriptionTimestampMargin __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Left content inset.
 */
@property (nonatomic, strong) NSNumber *leftInset __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Background color of the cell.
 */
@property (nonatomic, strong) UIColor *cellBackgroundColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


/**
 * Setup the cell with the request info.
 */
- (void) prepareWithRequest:(ZDKRequest*)request isUnread:(BOOL)isUnread;

@end


#pragma mark -


/**
 * Empty state cell for the request list.
 */
@interface ZDRequestListEmptyTableCell : UITableViewCell

/**
 * Empty cell text label.
 */
@property (nonatomic, strong) UILabel *messageLabel;

/**
 * Empty cell text font.
 */
@property (nonatomic, strong) UIFont *messageFont __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Empty cell text color.
 */
@property (nonatomic, strong) UIColor *messageColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


@end


#pragma mark -


/**
 * Loading state cell for the request list.
 */
@interface ZDRequestListLoadingTableCell : UITableViewCell

/**
 * Spinner to indicate the loading state.
 */
@property (nonatomic, strong) id<ZDKSpinnerDelegate> spinner __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


@end

