Pod::Spec.new do |s|
  s.name         = "ZendeskSDK"
  s.version      = "0.9.2"
  s.summary      = "Zendesk SDK 0.9.2 beta"
  s.homepage     = "https://github.com/zendesk/zendesk_sdk_ios"
  s.license      = { 
    :type => 'Copyright', 
    :text => <<-LICENSE
      ## Copyright and license

      Copyright 2014 Zendesk

      Licensed under the Apache License, Version 2.0 (the "License"); you may not 
      use this file except in compliance with the License.
      You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

      Unless required by applicable law or agreed to in writing, software distributed 
      under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS 
      OF ANY KIND, either express or implied. See the License for the specific language governing 
      permissions and limitations under the License.

      LICENSE
  }
  s.author       = 'Zendesk'
  s.source       = { :git => "https://github.com/zendesk/zendesk_sdk_ios.git", :tag => s.version.to_s }
  s.platform     = :ios, '6.0'
  s.source_files = 'ZendeskSDK.framework/Versions/A/Headers/*.h'
  s.requires_arc = true
  s.ios.vendored_frameworks = 'ZendeskSDK.framework'
  s.xcconfig = { 'FRAMEWORK_SEARCH_PATHS' => '$(inherited)' }
  s.preserve_paths = 'ZendeskSDK.framework'
  s.resources = ["ZendeskSDK.bundle", "ZendeskSDKStrings.bundle"]
end