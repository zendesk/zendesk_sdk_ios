//
//  ZDKRequestCommentsTable.h
//  ZendeskSDK
//
//  Created by Zendesk on 18/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "ZDKAPI.h"
#import "ZDKRequestCommentTableCell.h"


/**
 * Table presenting the list of comments for a request.
 */
@interface ZDKRequestCommentsTable : UITableView <UITableViewDataSource, UITableViewDelegate, ZDKCommentListRetryDelegate>


/**
 * A cache of the avatar images being presented in this table.
 */
@property (nonatomic, strong) NSMutableDictionary *avatarCache;

/**
 * The request object for this comment table is for.
 */
@property (nonatomic, strong) ZDKRequest *request;

/**
 * The list of comments being rendered.
 */
@property (nonatomic, strong) NSArray *comments;

/**
 * State tracking, if true then a refresh if the request list is in progress.
 */
@property (nonatomic, assign) BOOL loadingInProgress;

/**
 * State tracking, if true then the current state is that the last request to get comments for the request resulted in an error.
 */
@property (nonatomic, assign) BOOL fetchCommentsErrored;

@property (nonatomic, retain) NSString *errorString;

/**
 * Init with provided frame and request.
 *
 * @param frame the frame in which to render the UI
 * @param theRequest the request object this comment is for
 * @return the instance
 */
- (instancetype) initWithFrame:(CGRect)frame andRequest:(ZDKRequest*)theRequest;


@end

