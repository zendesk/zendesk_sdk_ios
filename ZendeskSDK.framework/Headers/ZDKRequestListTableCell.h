/*
 *
 *  ZDKRequestListTableCell.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 14/06/2014.  
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
 * The color of the unread marker.
 */
@property (nonatomic, strong) UIColor *unreadColor UI_APPEARANCE_SELECTOR;

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

@end


#pragma mark -


/**
 * Loading state cell for the request list.
 */
@interface ZDRequestListLoadingTableCell : UITableViewCell


@end

