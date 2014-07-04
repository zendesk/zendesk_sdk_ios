//
//  ZDRequestCommentsTable.h
//  CoreSDK
//
//  Created by Zendesk on 18/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "ZDAPI.h"


/**
 * Table presenting the list of comments for a request.
 */
@interface ZDRequestCommentsTable : UITableView <UITableViewDataSource, UITableViewDelegate>


/**
 * A cache of the avatar images being presented in this table.
 */
@property (nonatomic, strong) NSMutableDictionary *avatarCache;

/**
 * The request object for this comment table is for.
 */
@property (nonatomic, strong) ZDRequest *request;

/**
 * The list of comments being rendered.
 */
@property (nonatomic, strong) NSArray *comments;


/**
 * Init with provided frame and request.
 *
 * @param frame the frame in which to render the UI
 * @param request the request object this comment is for
 * @return the instance
 */
- (instancetype) initWithFrame:(CGRect)frame andRequest:(ZDRequest*)theRequest;


@end

