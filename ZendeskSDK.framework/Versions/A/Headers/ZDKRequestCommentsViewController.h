//
//  ZDKRequestCommentsViewController.h
//  ZendeskSDK
//
//  Created by Zendesk on 18/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDKUIViewController.h"
#import "ZDKAPI.h"
#import "ZDKRequestCommentsView.h"


/**
 * View controller for presenting the request comments and add-comment interface.
 */
@interface ZDKRequestCommentsViewController : ZDKUIViewController


/**
 * The request object for this comment view is for.
 */
@property (nonatomic, strong) ZDKRequest *request;


/**
 * The comments view for presenting the request details.
 */
@property (nonatomic, strong) ZDKRequestCommentsView *commentsView;


/**
 * Init with provided request.
 *
 * @param request the request object this comments view is for
 * @return the instance
 */
- (instancetype) initWithRequest:(ZDKRequest*)request;


@end
