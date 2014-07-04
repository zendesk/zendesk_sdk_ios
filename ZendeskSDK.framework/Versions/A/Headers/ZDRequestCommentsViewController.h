//
//  ZDRequestCommentsViewController.h
//  CoreSDK
//
//  Created by Zendesk on 18/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDUIUIViewController.h"
#import "ZDAPI.h"
#import "ZDRequestCommentsView.h"


/**
 * View controller for presenting the request comments and add-comment interface.
 */
@interface ZDRequestCommentsViewController : ZDUIUIViewController


/**
 * The request object for this comment view is for.
 */
@property (nonatomic, strong) ZDRequest *request;

/**
 * The comments view for presenting the request details.
 */
@property (nonatomic, strong) ZDRequestCommentsView *commentsView;


/**
 * Init with provided request.
 *
 * @param request the request object this comments view is for
 * @return the instance
 */
- (instancetype) initWithRequest:(ZDRequest*)request;


@end

