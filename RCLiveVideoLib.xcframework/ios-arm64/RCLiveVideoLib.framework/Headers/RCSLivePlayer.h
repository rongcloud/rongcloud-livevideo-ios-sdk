//
//  RCSLivePlayer.h
//  RCLiveVideoLib
//
//  Created by shaoshuai on 2022/9/2.
//

#import "RCSProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol RCSLivePlayer <RCSProtocol>

- (void)start:(NSString *)roomId;

- (void)stop;

@end

NS_ASSUME_NONNULL_END
