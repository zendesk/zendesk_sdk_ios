/*
 *
 *  ZDKAgentCommentTableCell.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 18/06/2014.  
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
#import "ZDKSpinnerDelegate.h"
@class ZDKCommentWithUser;

/**
 * Super class for request comment cells with shared functionality
 */
@interface ZDKRequestCommentTableCell : UITableViewCell

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
 * @param commentWithUser the comment and user for a given comment
 */
- (void) prepareUsingCommentWithUser:(ZDKCommentWithUser *)commentWithUser;

/**
 *  Convenience method for cell reuse identifiers.
 *
 *  @return a cell reuse identifier derived from NSStringFromClass.
 */
+ (NSString *) reuseId;

@end


#pragma mark - agent



/**
 * Comment cell for rendering agent comments.
 */
@interface ZDKAgentCommentTableCell : ZDKRequestCommentTableCell


/**
 * A cache of the avatar image being presented in this cell.
 */
@property (nonatomic, strong) NSMutableDictionary *avatarCache;

/**
 * The avatar UIImageView.
 */
@property (nonatomic, strong) UIImageView *avatar;

/**
 * The author label.
 */
@property (nonatomic, strong) UILabel *author;

/**
 * Avatar diameter.
 */
@property (nonatomic, strong) NSNumber *avatarSize __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Agent name text font.
 */
@property (nonatomic, strong) UIFont *agentNameFont __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Agent name text color.
 */
@property (nonatomic, strong) UIColor *agentNameColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Font of the body text of the comment.
 */
@property (nonatomic, strong) UIFont *bodyFont __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Color of the body text of the comment.
 */
@property (nonatomic, strong) UIColor *bodyColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Timestamp label text font.
 */
@property (nonatomic, strong) UIFont *timestampFont __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Timestamp label text color.
 */
@property (nonatomic, strong) UIColor *timestampColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Background color of the comment cell.
 */
@property (nonatomic, strong) UIColor *cellBackground __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;



/**
 * Returns the cell height for the comment in the specified width.
 *
 * @param commentWithUser the comment to be evaluated
 * @param width the width the cell has available
 * @return the resulting cell height
 */
+ (CGFloat) cellHeightForCommentWithUser:(ZDKCommentWithUser*)commentWithUser inWidth:(CGFloat)width;


@end


#pragma mark - end user



/**
 * Comment cell for rendering end user comments.
 */
@interface ZDKEndUserCommentTableCell : ZDKRequestCommentTableCell


/**
 * Returns the cell height for the comment in the specified width.
 *
 * @param commentWithUser the comment to be evaluated
 * @param width the width the cell has available
 * @return the resulting cell height
 */
+ (CGFloat) cellHeightForCommentWithUser:(ZDKCommentWithUser*)commentWithUser inWidth:(CGFloat)width;


/**
 * Font of the body text of the comment.
 */
@property (nonatomic, strong) UIFont *bodyFont __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Color of the body text of the comment.
 */
@property (nonatomic, strong) UIColor *bodyColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Timestamp label text font.
 */
@property (nonatomic, strong) UIFont *timestampFont __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Timestamp label text color.
 */
@property (nonatomic, strong) UIColor *timestampColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Background color of the comment cell.
 */
@property (nonatomic, strong) UIColor *cellBackground __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

@end

#pragma mark -


/**
 * Retry delegate for requesting a refresh.
 */
@protocol ZDKCommentListRetryDelegate <NSObject>


/**
 * Refresh the request list.
 */
- (void) refresh;

@end


#pragma mark - Loading Cell


/**
 * Loading state cell for the request list.
 */
@interface ZDKCommentsListLoadingTableCell : UITableViewCell

/**
 * Left content inset.
 */
@property (nonatomic, strong) NSNumber *leftInset __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Spinner to indicate the loading state.
 */
@property (nonatomic, strong) id<ZDKSpinnerDelegate> spinner __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Background color of the comment cell.
 */
@property (nonatomic, strong) UIColor *cellBackground __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


@end

