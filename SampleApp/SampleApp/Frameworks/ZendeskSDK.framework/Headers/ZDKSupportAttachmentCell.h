/*
 *
 *  ZDKHelpCenterAttachmentCell.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 30/09/2014.  
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

@interface ZDKSupportAttachmentCell : UITableViewCell <UIAppearanceContainer>

#pragma mark - Properties

/**
 * A label which displays the articles parent category and section.
 *
 */
@property (nonatomic, strong, readonly) UILabel *fileSize;

/**
 * A label which displays the articles title.
 *
 */
@property (nonatomic, strong, readonly) UILabel *title;

/**
 * Background color for the view.
 */
@property (nonatomic, strong) UIColor *viewBackgroundColor UI_APPEARANCE_SELECTOR;


/**
 * Attatchment file size label font.
 */
@property (nonatomic, strong) UIFont *fileSizeLabelFont UI_APPEARANCE_SELECTOR;

/**
 *  Attatchment file size label colour.
 */
@property (nonatomic, strong) UIColor *fileSizeLabelColor UI_APPEARANCE_SELECTOR;

/**
 * Attatchment file size label background colour.
 */
@property (nonatomic, strong) UIColor *fileSizeLabelBackground UI_APPEARANCE_SELECTOR;

/**
 * Title label font.
 */
@property (nonatomic, strong) UIFont *titleLabelFont UI_APPEARANCE_SELECTOR;

/**
 * Title label colour.
 */
@property (nonatomic, strong) UIColor *titleLabelColor UI_APPEARANCE_SELECTOR;

/**
 * Title label background colour.
 */
@property (nonatomic, strong) UIColor *titleLabelBackground UI_APPEARANCE_SELECTOR;

#pragma mark - Methods

/**
 * Helper method to retrieve this classes cell identifier.
 *
 * @returns The classes cell identifier.
 */
+ (NSString *) cellIdentifier;



@end
