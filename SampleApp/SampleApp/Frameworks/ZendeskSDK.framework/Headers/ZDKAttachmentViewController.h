/*
 *
 *  ZDKAttachmentViewController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 02/02/2015.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>


@class ZDKAttachmentView;


@protocol ZDKAttachmentViewControllerDelegate <NSObject>

- (void) didCloseAttachmentView;

- (void) attachmentTooLarge:(NSData *)data;

- (void) attachmentsView:(ZDKAttachmentView *)attachmentView didSelectAttachment:(NSString *)attachment data:(NSData*)data;

- (void) attachmentsView:(ZDKAttachmentView *)attachmentView didRemoveAttachment:(NSString *)attachment;

@end


@class ZDKAttachmentViewDataSource;


/**
 *  Controller for attachment view. 
 */
@interface ZDKAttachmentViewController : UIViewController


/**
 *  Attachment view delegate.
 */
@property (nonatomic, weak) id<ZDKAttachmentViewControllerDelegate>delegate;


@property (nonatomic) ZDKAttachmentView *attachmentView;


@property (nonatomic, readonly) ZDKAttachmentViewDataSource *datasource;


- (void) resetAttachmentsView;

@end
