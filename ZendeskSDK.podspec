Pod::Spec.new do |s|
  s.name         = "ZendeskSDK"
  s.version      = "1.3.0.1"
  s.summary      = "Zendesk SDK 1.3.0.1"
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
  s.source       = { :git => "https://github.com/zendesk/zendesk_sdk_ios.git", :tag => s.version.to_s }
  s.platform     = :ios, '6.0'
  s.requires_arc = true

  # Using subspecs to support installation without Localization part
  s.default_subspecs = 'Core', 'Localization'

  s.subspec 'Core' do |ss|
    ss.public_header_files = 'ZendeskSDK.framework/Headers/*.h'
    ss.ios.vendored_frameworks = 'ZendeskSDK.framework'
    ss.preserve_paths = 'ZendeskSDK.framework'
    ss.xcconfig = { 'FRAMEWORK_SEARCH_PATHS' => '$(inherited)' }
    ss.resources = ["ZendeskSDK.bundle"]
  end

  s.subspec 'Localization' do |ss|
    ss.resources = ["ZendeskSDKStrings.bundle"]
    ss.dependency 'ZendeskSDK/Core'
  end

end
