/*
 *
 *  ZDKRequestListViewController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 15/10/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import "ZDKUIViewController.h"

@class ZDKRequestListTable;

@protocol ZDKCreateRequestUIDelegate;

@interface ZDKRequestListViewController : ZDKUIViewController

/**
 *  Scroll view that contains the ZDKRequestListTable.
 */
@property (nonatomic, strong) UIScrollView *requestListContainer;

/**
 *  A table that displays open requests.
 */
@property (nonatomic, strong) ZDKRequestListTable *requestList;

/**
 *  Delegate for nav ban button UI. 
 */
@property (nonatomic, weak) id<ZDKCreateRequestUIDelegate> delegate;


/**
 *  Dismiss modally presented controller.
 *
 *  @since 1.5.4.1
 */
- (void) dismiss;

@end
