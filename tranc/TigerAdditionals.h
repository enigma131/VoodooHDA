/*
 *  TigerAdditionals.h
 *  VoodooHDA
 *
 *  Created by Andy Vandijck on 12/03/10.
 *  Copyright 2010 AnV Software. All rights reserved.
 *
 */

#ifdef TIGER // needed for compile fix...
int vprintf_vhda(const char *fmt, va_list ap);
int snprintf_vhda(char *text, size_t maxlen, const char *fmt, ...);

#define vprintf vprintf_vhda
#define snprintf snprintf_vhda
#define strlcpy strncpy
#define strlcat strncat

#define kIOAudioDeviceTransportTypeHdmi 'hdmi'
#define kIOAudioChannelLabel_Left 1
#define kIOAudioChannelLabel_Right 2
#define kIOAudioChannelLabel_Center 3
#define kIOAudioChannelLabel_LFEScreen 4
#define kIOAudioChannelLabel_LeftSurround 5
#define kIOAudioChannelLabel_RightSurround 6
#define kIOAudioChannelLabel_RearSurroundLeft 33
#define kIOAudioChannelLabel_RearSurroundRight 34
#define kIOAudioEngineInputChannelLayoutKey "IOAudioEngineInputChannelLayout"
#define kIOAudioEngineOutputChannelLayoutKey "IOAudioEngineOutputChannelLayout"

enum {
    kIOUCVariableStructureSize = 0xffffffff
};
#endif

