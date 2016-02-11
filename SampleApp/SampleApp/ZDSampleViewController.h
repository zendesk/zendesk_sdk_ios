//
//  ZDSampleViewController.h
//  SampleApp
//
//  Created by Zendesk on 25/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <ZendeskSDK/ZendeskSDK.h>
#import "ZDSampleAppConfigurationViewController.h"

#define APPLE_PUSH_UUID @"ZDKPushUUIDKey"


@interface ZDSampleViewController : ZDKUIViewController <ZDAppConfigurationDelegate, UITextFieldDelegate>


@property (nonatomic, strong) UIButton *requestCreationButton;
@property (nonatomic, strong) UIButton *requestListButton;
@property (nonatomic, strong) UITextField *helpCenterLabelsInput;
@property (nonatomic, strong) UIButton *helpCenterButton;
@property (nonatomic, strong) UIButton *helpCenterWithFlatArticlesButton;
@property (nonatomic, strong) UIButton *rmaButton;
@property (nonatomic, strong) UINavigationController *modalNavController;
@property (nonatomic, strong) UIButton *registerPush;
@property (nonatomic, strong) UIButton *unregisterPush;
@property (nonatomic, strong) UITextField *helpCenterCategoryIdInput;
@property (nonatomic, strong) UITextField *helpCenterSectionIdInput;
@property (nonatomic, strong) UITextField *userTagsInput;
@property (nonatomic, strong) UIButton *addTagsButton;
@property (nonatomic, strong) UIButton *removeTagsButton;


/**
 *  Helper method to build a UITextField with a specified frame.
 *
 *  @param frame       Size of text field.
 *  @param placeholder Placeholder text.
 *
 *  @return A UITextField.
 */
+ (UITextField *) buildTextFieldWithFrame:(CGRect)frame andPlaceholder:(NSString *)placeholder;

/**
 *  Helper method to build a UIButton with a specified frame.
 *
 *  @param frame Size of the button.
 *  @param title Button title.
 *
 *  @return A UIButton.
 */
+ (UIButton *) buildButtonWithFrame:(CGRect)frame andTitle:(NSString*)title;




@end

