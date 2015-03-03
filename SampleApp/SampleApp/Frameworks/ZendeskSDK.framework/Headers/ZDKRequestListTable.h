/*
 *
 *  ZDKRequestListTable.h
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
#import "ZDKRequestListTableCell.h"


#define ZDSDK_REQUEST_LIST_BACKGROUND_COLOR [UIColor clearColor]
#define ZDSDK_REQUEST_CELL_SEPARATOR_COLOR [UIColor colorWithWhite:0.90f alpha:1.0f]


/**
 * UITableView containing the users request list. On init, the list will show a loading indicator 
 * and refresh the requests from the server, once loaded the list will reload itself and will notify 
 * that the table has been updated.
 */
@interface ZDKRequestListTable : UITableView <UITableViewDataSource, UITableViewDelegate, ZDRequestListRetryDelegate>

/**
 * The array of requests that is being used tpo render the table.
 */
@property (nonatomic, strong) NSArray *requests;

/**
 * State tracking, if true then the current state is that the last refresh resulted in an error.
 */
@property (nonatomic, assign) BOOL refreshError;

/**
 * Localised error string for presentation to the user.
 */
@property (nonatomic, strong) NSString *errorString;

/**
 * State tracking, if true then a refresh if the request list is in progress.
 */
@property (nonatomic, assign) BOOL loadingInProgress;

/**
 * Color for the cell separators in the table.
 */
@property (nonatomic, strong) UIColor *cellSeparatorColor UI_APPEARANCE_SELECTOR;

/**
 * The background color of the request table.
 */
@property (nonatomic, strong) UIColor *tableBackgroundColor UI_APPEARANCE_SELECTOR;


/**
 * Refresh the requests list from the server.
 */
- (void) refresh;


/**
 * Returns the height required by the table to display it's contents.
 */
- (CGFloat) tableHeight;


/**
 *  Returns the cell height for the current table state, e.g. loading or loaded.
 *
 *  @return a table cell height. 
 */
- (CGFloat) cellHeight;


/**
 * Register the observer for NSNotification events that the list has been updated.
 *
 * @param observer the instance to be added as observer
 * @param selector the selector to be invoked on the observer on event
 */
- (void) registerForEvents:(id)observer withSelector:(SEL)selector;


/**
 * Remove the observer, this must always be invoked on observer dealloc.
 *
 * @param observer the instance to be removed as observer
 */
- (void) unregisterForEvents:(id)observer;


@end

