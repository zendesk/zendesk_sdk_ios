/*
 *
 *  ZDKCommentsTableViewDataSource.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 04/02/2015.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>

@class ZDKRequest;


extern NSString * const ZDK_RequestCommentsListUpdated;

/**
 *  Data source for the comments table view.
 */
@interface ZDKCommentsTableViewDataSource : NSObject <UITableViewDataSource>


/**
 * State tracking, if true then a refresh if the request list is in progress.
 */
@property (nonatomic, assign, readonly) BOOL loadingInProgress;


/**
 * Read-only array of items associated with the data source.
 */
@property (nonatomic, copy, readonly) NSArray *items;


/**
 * Init with provided request.
 *
 * @param request the request object this comments view is for
 * @return the instance
 */
- (instancetype) initWithRequest:(ZDKRequest*)request;


/**
 * Retrieves an item for the given index path.
 *
 * @param indexPath The index path for the item to be retrieved.
 * @return An item, depending on the data source this could be a category, section or article.
 */
- (id)itemAtIndexPath:(NSIndexPath *)indexPath;


/**
 * Reloads the data source.
 */
- (void) reloadData;


@end
