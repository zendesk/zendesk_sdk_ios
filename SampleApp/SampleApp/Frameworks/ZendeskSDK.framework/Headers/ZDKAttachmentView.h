/*
 *
 *  ZDKAttachmentView.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 03/02/2015.
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
 *  A small view which displays attachments for a comment being created.
 *  Allowing end users to add and remove attachments to comments. 
 */
@interface ZDKAttachmentView : UIView


/**
 *  Collection view for attachments.
 */
@property (nonatomic, strong, readonly) UICollectionView *attachmentsCollectionView;


/**
 *  Add a target for the close button accion on this view.
 *
 *  @param target the target for the action.
 *  @param action the action.
 */
- (void) addTarget:(id)target forCloseAction:(SEL)action;


@end
