Pod::Spec.new do |s|
  s.name      = 'RCLiveVideoLib'
  s.version   = "2.1.2"
  s.summary   = 'live video'
  
  s.description      = <<-DESC
  live video dependency IM & RTC
  DESC
  
  s.homepage         = 'https://github.com/rongcloud'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'shaoshuai' => 'shaoshuai@rongcloud.cn' }
  s.source       = { :git => 'https://github.com/rongcloud/rongcloud-livevideo-ios-sdk.git', :tag => s.version.to_s }
  
  s.ios.deployment_target = '11.0'
  
  s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
    'VALID_ARCHS' => 'arm64 x86_64',
  }
  s.source_files = 'RCLiveVideoLib/Classes/**/*'
  s.public_header_files = 'Pod/Classes/Header/RCLiveVideoLib.h'
  
  s.dependency 'RongCloudRTC/RongRTCLib'
  s.dependency 'RongCloudIM/ChatRoom'
  
end
