/*
 *
 *  ZDKRequestListTable.h
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




@class ZDKRequestStorage;

/**
 * UITableView containing the users request list. On init, the list will show a loading indicator 
 * and refresh the requests from the server, once loaded the list will reload itself and will notify 
 * that the table has been updated.
 */
@interface ZDKRequestListTable : UITableView <UITableViewDataSource, UITableViewDelegate>

/**
 * The array of requests that is being used to render the table.
 */
@property (nonatomic, copy) NSArray *requests;

/**
 * State tracking, if true then the current state is that the last refresh resulted in an error.
 */
@property (nonatomic, assign) BOOL refreshError;

/**
 * Localized error string for presentation to the user.
 */
@property (nonatomic, copy) NSString *errorString;

/**
 * State tracking, if true then a refresh if the request list is in progress.
 */
@property (nonatomic, assign) BOOL loadingInProgress;

/**
 *  create a request list table
 *
 *  @param requestStorage       request storage to use
 */
- (instancetype) initWithRequestStorage:(ZDKRequestStorage*)requestStorage NS_DESIGNATED_INITIALIZER;


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


- (instancetype)initWithFrame:(CGRect)frame style:(UITableViewStyle)style NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

