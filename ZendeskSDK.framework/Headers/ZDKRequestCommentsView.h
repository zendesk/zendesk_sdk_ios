/*
 *
 *  ZDKRequestCommentsView.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 19/06/2014.  
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
#import "ZDKAPIDispatcher.h"
#import "ZDKRequestCommentsTable.h"
#import "ZDKCommentEntryView.h"


/**
 * Comments view containing the comments list/table and the comment entry and addition view.
 */
__deprecated_msg(" As of version 1.1.1.1")
@interface ZDKRequestCommentsView : UIView <UITextViewDelegate>


/**
 * The request object for this comment view is for.
 */
@property (nonatomic, strong) ZDKRequest *request;

/**
 * The comments table listing all current comments for this request.
 */
@property (nonatomic, strong) ZDKRequestCommentsTable *commentsTable;

/**
 * The comment text entry and send button view.
 */
@property (nonatomic, strong) ZDKCommentEntryView *commentEntryView;


/**
 * Init with provided frame and request.
 *
 * @param frame the frame in which to render the UI
 * @param theRequest the request object this comment is for
 * @return the instance
 */
- (instancetype) initWithFrame:(CGRect)frame andRequest:(ZDKRequest*)theRequest;


@end

