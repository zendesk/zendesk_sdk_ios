/*
 *
 *  ZDKRequestCommentAttachmentTableCell.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 22/01/2015.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import "ZDKRequestCommentTableCell.h"


@interface ZDKRequestCommentAttachmentTableCell : ZDKRequestCommentTableCell


/**
 *  Sets up this cell with the UIImage parameter.
 *
 *  @param attachment a UIImage that will be displayed in the cell.
 *  @param constraint A max width for the image. This is used to resize the image to save memory.
 *
 *  @since 1.4.0.1
 */
- (void) prepareWithImage:(UIImage *)attachment andWidthConstraint:(CGFloat)constraint;

/**
 *  Sets up this cell with the UIImage parameter.
 *
 *  @param attachment a UIImage that will be displayed in the cell.
 */
- (void) prepareWithImage:(UIImage *)attachment __deprecated_msg(" As of version 1.4.0.1");


/**
 *  Get the total amount of virticle padding for content in this cell.
 *
 *  @return a CGFloat value for the padding in this cell.
 */
+ (CGFloat) virticlePadding;


@end
