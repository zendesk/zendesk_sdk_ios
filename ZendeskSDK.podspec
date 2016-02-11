Pod::Spec.new do |s|
  s.name         = "ZendeskSDK"
  s.version      = "1.5.4.1"
  s.summary      = "Zendesk SDK 1.5.4.1"
  s.homepage     = "https://github.com/zendesk/zendesk_sdk_ios"
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE

     ZendeskSDK

     Created by Zendesk on 25/02/2014.

     Copyright (c) 2014 Zendesk. All rights reserved.

     By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
     of Service https://www.zendesk.com/company/terms and Application Developer and API License
     Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
     acknowledge that such terms govern Your use of and access to the Mobile SDK.

     LICENSE
  }
  s.author       = 'Zendesk'
  s.source       = { :git => "https://github.com/zendesk/zendesk_sdk_ios.git", :tag => s.version }
  s.platform     = :ios, '6.0'
  s.requires_arc = true
  s.frameworks = 'MobileCoreServices', 'SystemConfiguration', 'Security', 'MessageUI'

  # Using subspecs to support installation without Localization part
  s.default_subspecs = 'Core', 'Localization', 'Providers'

  s.subspec 'Core' do |ss|
    ss.public_header_files = 'ZendeskSDK.framework/Headers/*.h'
    ss.ios.vendored_frameworks = 'ZendeskSDK.framework'
    ss.preserve_paths = 'ZendeskSDK.framework'
    ss.xcconfig = { 'FRAMEWORK_SEARCH_PATHS' => '$(inherited)', 'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES' }
    ss.resources = ["ZendeskSDK.bundle"]
  end

  s.subspec 'Localization' do |ss|
    ss.resources = ["ZendeskSDKStrings.bundle"]
    ss.dependency 'ZendeskSDK/Core'
  end

  s.subspec 'Providers' do |ss|
    ss.public_header_files = 'ZendeskProviderSDK.framework/Headers/*.h'
    ss.ios.vendored_frameworks = 'ZendeskProviderSDK.framework'
    ss.preserve_paths = 'ZendeskProviderSDK.framework'
    ss.xcconfig = { 'FRAMEWORK_SEARCH_PATHS' => '$(inherited)', 'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES' }
    ss.resources = ["ZendeskSDK.bundle", "ZendeskSDKStrings.bundle"]
  end

end
