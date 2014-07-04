//
//  ZDAgentCommentTableCell.h
//  CoreSDK
//
//  Created by Zendesk on 18/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "ZDAPI.h"


#define ZD_COMMENT_CELL_AGENT_BODY_FONT [UIFont systemFontOfSize:15.0f];
#define ZD_COMMENT_CELL_AGENT_BODY_COLOR [UIColor colorWithWhite:0.38f alpha:1.0f];
#define ZD_COMMENT_CELL_AGENT_BG_COLOR [UIColor whiteColor]
#define ZD_COMMENT_CELL_AGENT_TIMESTAMP_FONT [UIFont systemFontOfSize:11.0f]
#define ZD_COMMENT_CELL_AGENT_TIMESTAMP_COLOR [UIColor colorWithWhite:0.721f alpha:1.0f]


/**
 * Super class for request comment cells with shared functionality
 */
@interface ZDRequestCommentTableCell : UITableViewCell


/**
 * The comment object being presented.
 */
@property (nonatomic, strong) ZDRequestComment *comment;

/**
 * The label containing the body of the comment.
 */
@property (nonatomic, strong) UILabel *body;

/**
 * The 'created at' label.
 */
@property (nonatomic, strong) UILabel *timestamp;


/**
 * Setup the cell for rendering with the provided comment.
 *
 * @param comment the comment to prepare the cell with
 */
- (void) prepareWithComment:(ZDRequestComment*)comment;


@end


#pragma mark - agent


#define ZD_COMMENT_CELL_AGENT_AVATAR_SIZE 40.0f
#define ZD_COMMENT_CELL_AGENT_NAME_FONT [UIFont systemFontOfSize:14.0f]
#define ZD_COMMENT_CELL_AGENT_NAME_COLOR [UIColor colorWithWhite:0.25f alpha:1.0f]


/**
 * Comment cell for rendering agent comments.
 */
@interface ZDAgentCommentTableCell : ZDRequestCommentTableCell


/**
 * A cache of the avatar image being presented in this cell.
 */
@property (nonatomic, strong) NSMutableDictionary *avatarCache;

/**
 * The avatar UIImageview.
 */
@property (nonatomic, strong) UIImageView *avatar;

/**
 * The author label.
 */
@property (nonatomic, strong) UILabel *author;

/**
 * Avatar diameter.
 */
@property (nonatomic, assign) CGFloat avatarSize UI_APPEARANCE_SELECTOR;

/**
 * Agent name text font.
 */
@property (nonatomic, strong) UIFont *agentNameFont UI_APPEARANCE_SELECTOR;

/**
 * Agent name text color.
 */
@property (nonatomic, strong) UIColor *agentNameColor UI_APPEARANCE_SELECTOR;

/**
 * Font of the body text of the comment.
 */
@property (nonatomic, strong) UIFont *bodyFont UI_APPEARANCE_SELECTOR;

/**
 * Color of the body text of the comment.
 */
@property (nonatomic, strong) UIColor *bodyColor UI_APPEARANCE_SELECTOR;

/**
 * Timestamp label text font.
 */
@property (nonatomic, strong) UIFont *timestampFont UI_APPEARANCE_SELECTOR;

/**
 * Timestamp label text color.
 */
@property (nonatomic, strong) UIColor *timestampColor UI_APPEARANCE_SELECTOR;

/**
 * Background color of the comment cell.
 */
@property (nonatomic, strong) UIColor *cellBackground UI_APPEARANCE_SELECTOR;



/**
 * Returns the cell height for the comment in the specified width.
 *
 * @param comment the comment to be evaluated
 * @param width the width the cell has available
 * @return the resulting cell height
 */
+ (CGFloat) cellHeightForComment:(ZDRequestComment*)comment inWidth:(CGFloat)width;


@end


#pragma mark - end user


#define ZD_COMMENT_CELL_ENDUSER_BODY_FONT [UIFont systemFontOfSize:15.0f]
#define ZD_COMMENT_CELL_ENDUSER_BODY_COLOR [UIColor colorWithWhite:0.38f alpha:1.0f]
#define ZD_COMMENT_CELL_ENDUSER_BG_COLOR [UIColor colorWithWhite:0.976f alpha:1.0f]


/**
 * Comment cell for rendering end user comments.
 */
@interface ZDEndUserCommentTableCell : ZDRequestCommentTableCell


/**
 * Returns the cell height for the comment in the specified width.
 *
 * @param comment the comment to be evaluated
 * @param width the width the cell has available
 * @return the resulting cell height
 */
+ (CGFloat) cellHeightForComment:(ZDRequestComment*)comment inWidth:(CGFloat)width;


/**
 * Font of the body text of the comment.
 */
@property (nonatomic, strong) UIFont *bodyFont UI_APPEARANCE_SELECTOR;

/**
 * Color of the body text of the comment.
 */
@property (nonatomic, strong) UIColor *bodyColor UI_APPEARANCE_SELECTOR;

/**
 * Timestamp label text font.
 */
@property (nonatomic, strong) UIFont *timestampFont UI_APPEARANCE_SELECTOR;

/**
 * Timestamp label text color.
 */
@property (nonatomic, strong) UIColor *timestampColor UI_APPEARANCE_SELECTOR;

/**
 * Background color of the comment cell.
 */
@property (nonatomic, strong) UIColor *cellBackground UI_APPEARANCE_SELECTOR;



@end

