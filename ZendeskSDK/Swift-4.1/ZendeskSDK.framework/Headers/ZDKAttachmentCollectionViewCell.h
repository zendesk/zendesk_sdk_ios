/*
 *
 *  ZDKAttachmentCollectionViewCell.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 02/02/2015.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>


/**
 *  Collection view cell which displays an attachment.
 */
@interface ZDKAttachmentCollectionViewCell : UICollectionViewCell


/**
 *  Prepare cell for display with an image.
 *
 *  @param image an attachment to display.
 */
- (void)prepareWithImage:(UIImage *)image;


/**
 *  Helper method.
 *
 *  @return a reuse identifier.
 */
+ (NSString *) reuseIdentifier;


/**
 *  Returns the preferred size for the view.
 */
+ (CGSize) preferedSize;


@end
