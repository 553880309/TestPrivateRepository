#
# Be sure to run `pod lib lint TestPrivateRepo.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'TestPrivateRepo'
  s.version          = '0.1.0'
  s.summary          = 'A short description of TestPrivateRepo.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
    尝试封装第三方库于私有库当中进行使用。
                       DESC

  s.homepage         = 'https://github.com/553880309/TestPrivateRepo'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { '553880309' => 'wuchunyan@58ganji.com' }
  s.source           = { :git => 'https://github.com/553880309/TestPrivateRepository.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'
  
  # s.resource_bundles = {
  #   'TestPrivateRepo' => ['TestPrivateRepo/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'

    s.subspec 'RongIMLib' do |ss|
        ss.ios.vendored_frameworks = 'TestPrivateRepo/Classes/RongCloud/RongIMLib.framework'
        ss.ios.vendored_library = 'TestPrivateRepo/Classes/RongCloud/libopencore-amrnb.a'
        ss.libraries = 'c++', 'c++abi', 'sqlite3', 'stdc++.6.0.9', 'xml2', 'z'
        ss.frameworks = 'CFNetwork', 'SystemConfiguration'
    end
    
    # 58 推送
    # 文档地址：http://wiki.58corp.com/index.php?title=WPush
    s.subspec 'WBPush' do |ss|
        ss.source_files = 'TestPrivateRepo/Classes/WBPush/Headers/*.h'
        ss.ios.vendored_library = 'TestPrivateRepo/Classes/WBPush/libWUBAPush.a'
        ss.frameworks = 'PushKit', 'CoreLocation'
    end

    s.subspec 'WChat' do |ss|
        ss.source_files = 'TestPrivateRepo/Classes/WChat/WChatLib/*.h'
        ss.ios.vendored_libraries = ['TestPrivateRepo/Classes/WChat/WChatLib.a','TestPrivateRepo/Classes/WChat/libWMDA_Lite.a','TestPrivateRepo/Classes/WChat/libcrypto.a','TestPrivateRepo/Classes/WChat/libssl.a']
        ss.libraries = 'c++', 'sqlite3', 'resolv.9', 'z'
        ss.frameworks = 'SystemConfiguration', 'CoreTelephony', 'CoreFoundation', 'QuartzCore', 'AVFoundation', 'AssetsLibrary', 'Photos', 'MobileCoreServices', 'MediaPlayer', 'CoreLocation', 'MapKit', 'CoreAudio', 'AudioToolbox', 'ImageIO', 'CoreText'
     end

end
