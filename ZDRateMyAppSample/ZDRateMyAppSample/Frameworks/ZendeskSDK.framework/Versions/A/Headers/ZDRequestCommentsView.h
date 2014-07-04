//
//  ZDRequestCommentsView.h
//  CoreSDK
//
//  Created by Zendesk on 19/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "ZDAPI.h"
#import "ZDRequestCommentsTable.h"
#import "ZDCommentEntryView.h"


/**
 * Comments view containing the comments list/table and the comment entry and addition view.
 */
@interface ZDRequestCommentsView : UIView <UITextViewDelegate>


/**
 * The request object for this comment view is for.
 */
@property (nonatomic, strong) ZDRequest *request;

/**
 * The comments table listing all current comments for this request.
 */
@property (nonatomic, strong) ZDRequestCommentsTable *commentsTable;

/**
 * The comment text entry and send button view.
 */
@property (nonatomic, strong) ZDCommentEntryView *commentEntryView;


/**
 * Init with provided frame and request.
 *
 * @param frame the frame in which to render the UI
 * @param request the request object this comment is for
 * @return the instance
 */
- (instancetype) initWithFrame:(CGRect)frame andRequest:(ZDRequest*)theRequest;


@end

