Pod::Spec.new do |s|
  s.name         = "ZendeskSDK"
  s.version      = "2.3.1"
  s.summary      = "Zendesk SDK 2.3.1"
  s.homepage     = "https://github.com/zendesk/zendesk_sdk_ios"
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
    ZendeskSDK
    Created by Zendesk on  3/30/2017
    Copyright (c) 2017 Zendesk. All rights reserved.
    By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
    Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
    Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
    acknowledge that such terms govern Your use of and access to the Mobile SDK.
    LICENSE
  }
  s.author       = 'Zendesk'
  s.source       = { :git => "https://github.com/zendesk/zendesk_sdk_ios.git", :tag => s.version }
  s.platform     = :ios, '9.0'
  s.requires_arc = true
  s.frameworks = 'MobileCoreServices', 'SystemConfiguration', 'Security', 'MessageUI'
  s.swift_version = "5.0"
  s.xcconfig = { 'FRAMEWORK_SEARCH_PATHS' => '$(inherited)', 'CLANG_ENABLE_MODULES' => 'YES', 'ALWAYS_EMBED_SWIFT_STANDARD_LIBRARIES' => 'YES' }
    

  # Using subspecs to support installation without Localization part
  s.default_subspecs = 'UI', 'Providers'

  s.subspec 'UI' do |ss|
    ss.platform     = :ios, '9.0'
    ss.ios.vendored_frameworks = "ZendeskSDK/#{s.swift_version.to_s}/ZendeskSDK.framework"
    ss.preserve_paths = "ZendeskSDK/#{s.swift_version.to_s}/ZendeskSDK.framework"
    ss.resources = ["ZendeskSDK/#{s.swift_version.to_s}/ZendeskSDKStrings.bundle"]
    ss.dependency 'ZendeskSDK/Providers'
    ss.dependency 'ZendeskSDK/Core'
  end

  s.subspec 'Providers' do |ss|
    ss.platform     = :ios, '9.0'
    ss.ios.vendored_frameworks = "ZendeskSDK/#{s.swift_version.to_s}/ZendeskProviderSDK.framework"
    ss.preserve_paths = "ZendeskSDK/#{s.swift_version.to_s}/ZendeskProviderSDK.framework"
    ss.dependency 'ZendeskSDK/Core'
  end

  s.subspec 'Core' do |ss|
    ss.platform     = :ios, '9.0'
    ss.ios.vendored_frameworks = "ZendeskSDK/#{s.swift_version.to_s}/ZendeskCoreSDK.framework"
    ss.preserve_paths = "ZendeskSDK/#{s.swift_version.to_s}/ZendeskCoreSDK.framework"
  end  

end
