//
//  ZDKHelpCenterCategoryDataSource.h
//  ZendeskSDK
//
//  Created by Zendesk on 10/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZDKHelpCenterProvider;


/**
 * A block for configuring cells. This is invoked in cell for row at index path.
 */
typedef void (^ZDKHelpCenterCellConfigureBlock)(id cell, id item);


/**
 * The support view that displays help center content.
 */
@interface ZDKHelpCenterDataSource : NSObject <UITableViewDataSource>


/**
 * Read only property, indicating if the DataSource has any items
 */
@property (nonatomic, readonly) BOOL hasItems;


/**
 * Reloads the data source. 
 */
- (void) reloadData;

/**
 * Retrieves an item for the given index path. 
 *
 * @param indexPath The index path for the item to be retrieved.
 * @return An item, depending on the data source this could be a category, section or article.
 */
- (id)itemAtIndexPath:(NSIndexPath *)indexPath;

/**
 * Initializes a data source with a cell identifire, configuration block and a provider.
 *
 * @param aCellIdentifier The identifier for table view cells created with this data source.
 * @param aConfigureCellBlock A configuration block for the table view cells created with this data source.
 * @param aProvider A subclass of ZDHelpCenterProvider which will supply the data source with it's data.
 * @param aParentId The parent ID for the resources in Help Center, or nil if there is no parent ID.
 */
- (instancetype) initWithcellIdentifier:(NSString *)aCellIdentifier
                     configureCellBlock:(ZDKHelpCenterCellConfigureBlock)aConfigureCellBlock
                               provider:(Class)aProvider
                            andParentId:(NSString *)aParentId;


/**
 * Initializes a data source with a cell identifire and configuration block.
 *
 * @param aCellIdentifier The identifier for table view cells created with this data source.
 * @param aConfigureCellBlock A configuration block for the table view cells created with this data source.
 * @param aQuery The query sent to help center.
 */
- (instancetype) initWithcellIdentifier:(NSString *)aCellIdentifier
                     configureCellBlock:(ZDKHelpCenterCellConfigureBlock)aConfigureCellBlock
                               andQuery:(NSString *)aQuery;


@end


