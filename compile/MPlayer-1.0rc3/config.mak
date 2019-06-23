# -------- Generated by configure -----------

# Ensure that locale settings do not interfere with shell commands.
export LC_ALL = C

CHARSET = UTF-8
DOC_LANG = zh_CN
DOC_LANGS =  zh_CN
DOC_LANG_ALL = cs de en es fr hu it pl ru zh_CN
MAN_LANG = zh_CN
MAN_LANGS =  zh_CN
MAN_LANG_ALL = cs de en es fr hu it pl ru zh_CN

prefix = $(DESTDIR)/usr/local
BINDIR = $(DESTDIR)/usr/local/bin
DATADIR = $(DESTDIR)/usr/local/share/mplayer
LIBDIR = $(DESTDIR)/usr/local/lib
MANDIR = $(DESTDIR)/usr/local/share/man
CONFDIR = $(DESTDIR)/usr/local/etc/mplayer

AR = ar
CC = arm-linux-gcc
CXX = arm-linux-gcc
HOST_CC = gcc
YASM = yasm
INSTALL = install
INSTALLSTRIP = -s
RANLIB = ranlib
WINDRES = windres

CFLAGS = -Wundef -Wdisabled-optimization -Wno-pointer-sign -Wdeclaration-after-statement -std=gnu99 -Wall -Wno-switch -Wpointer-arith -Wredundant-decls -O4   -pipe -ffast-math -fomit-frame-pointer -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -I.  
OPTFLAGS = -Wundef -Wdisabled-optimization -Wno-pointer-sign -Wdeclaration-after-statement -std=gnu99 -Wall -Wno-switch -Wpointer-arith -Wredundant-decls -O4   -pipe -ffast-math -fomit-frame-pointer -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -I.  
CXXFLAGS =  -Wall -Wno-switch -Wpointer-arith -Wredundant-decls -O4   -pipe -ffast-math -fomit-frame-pointer -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -D__STDC_LIMIT_MACROS -I.   
CFLAGS_DHAHELPER = 
CFLAGS_FAAD_FIXED = 
CFLAGS_LIBDVDCSS = 
CFLAGS_LIBDVDCSS_DVDREAD = 
CFLAGS_LIBDVDNAV = 
CFLAGS_NO_OMIT_LEAF_FRAME_POINTER = 
CFLAGS_STACKREALIGN = 
CFLAGS_SVGALIB_HELPER = 
CFLAGS_TREMOR_LOW = 
YASMFLAGS = 

EXTRALIBS = 
EXTRA_LIB = -Wl,-z,noexecstack  -ffast-math   -lncurses -lpng -lz -ljpeg -lasound -ldl -lpthread -lz -lpthread -ldl -rdynamic -static -lm
EXTRALIBS_MPLAYER = 
EXTRALIBS_MENCODER = 

DEPEND_CMD   = $(CC) -MM $(CFLAGS) $(filter-out %.h,$^) | sed "s,[0-9a-z._-]*: \($(SRC_DIR)/\)*\([a-z0-9]*/\)[^/]* ,\2&,"

MPDEPEND_CMD     = $(CC) -MM $(CFLAGS)   $(filter-out %.xpm,$(filter-out %.h,$^)) | sed -e "s,[0-9a-z._-]*: \([a-z0-9/]*/\)[^/]* ,\1&," -e "s,\(.*\)\.o: ,\1.d &,"
MPDEPEND_CMD_CXX = $(CC) -MM $(CXXFLAGS) $(filter-out %.hh,$(filter-out %.h,$^))  | sed -e "s,[0-9a-z._-]*: \([a-z0-9/]*/\)[^/]* ,\1&," -e "s,\(.*\)\.o: ,\1.d &,"

GETCH = getch2.c
HELP_FILE = help/help_mp-zh_CN.h
TIMER = timer-linux.c

EXESUF = 
EXESUFS_ALL = .exe

ARCH_ARM = yes

HAVE_ARMVFP=yes
HAVE_ARMV6=yes
HAVE_ARMV5TE=yes
HAVE_PLD=yes

MENCODER = no
MPLAYER = yes

NEED_GETTIMEOFDAY    = no
NEED_GLOB    = no
NEED_MMAP    = 
NEED_SETENV  = no
NEED_SHMEM   = yes
NEED_STRSEP  = no
NEED_SWAB    = no
NEED_VSSCANF = yes

# features
3DFX = no
AA = no
ALSA1X = yes
ALSA9 = 
ALSA5 = 
APPLE_IR = auto
APPLE_REMOTE = auto
ARTS = no
AUDIO_INPUT = 
BITMAP_FONT = yes
BL = no
CACA = no
CDDA = 
CDDB = no
COREAUDIO = 
COREVIDEO = 
DART = auto
DFBMGA = 
DGA = no
DIRECT3D = auto
DIRECTFB = no
DIRECTX = auto
DVBIN = yes
DVDNAV = no
DVDNAV_INTERNAL = no
DVDREAD = no
DVDREAD_INTERNAL = no
DXR2 = no
DXR3 = no
ESD = no
FAAC=no
FAAD = yes
FAAD_INTERNAL = yes
FASTMEMCPY = yes
FBDEV = yes
FREETYPE = no
FTP = yes
GIF = no
GGI = no
GL = no
GL_WIN32 = 
GUI = no
GUI_GTK = 
GUI_WIN32 = 
HAVE_POSIX_SELECT = yes
HAVE_SYS_MMAN_H = yes
IVTV = no
JACK = no
JOYSTICK = no
JPEG = yes
KVA = auto
LADSPA = no
LIBA52 = yes
LIBA52_INTERNAL = yes
LIBASS = no
LIBDCA = no
LIBDV = no
LIBDVDCSS_INTERNAL = no
LIBLZO = no
LIBMAD = no
LIBMENU = no
LIBMENU_DVBIN = no
LIBMPEG2 = yes
LIBNEMESI = no
LIBNUT = no
LIBSMBCLIENT = no
LIBTHEORA = no
LIBVORBIS = yes
LIRC = no
LIVE555 = no
MACOSX_BUNDLE = auto
MACOSX_FINDER = no
MD5SUM = yes
MGA = no
MNG = no
MP3LAME = auto
MP3LIB = no
MUSEPACK = no
NAS = no
NATIVE_RTSP = yes
NETWORK = yes
OPENAL = no
OSS = yes
PE_EXECUTABLE = 
PNG = yes
PNM = yes
PRIORITY = no
PULSE = no
PVR = no
QTX_CODECS = auto
QTX_CODECS_WIN32 = 
QTX_EMULATION = no
QUARTZ = 
RADIO=no
RADIO_CAPTURE=no
REAL_CODECS = no
S3FB = no
SDL = no
SPEEX = no
STREAM_CACHE = yes
SGIAUDIO = auto
SUNAUDIO = no
SVGA = no
TDFXFB = no
TDFXVID = no
TGA = yes
TOOLAME=no
TREMOR_INTERNAL = yes
TV = yes
TV_BSDBT848 = auto
TV_DSHOW = no
TV_TELETEXT = no
TV_V4L  = 
TV_V4L1 = no
TV_V4L2 = no
TWOLAME=no
UNRAR_EXEC = yes
V4L2 = yes
VCD = no
VDPAU = no
VESA = no
VIDIX = no
VIDIX_PCIDB = 
VIDIX_CYBERBLADE=no
VIDIX_IVTV=no
VIDIX_MACH64=no
VIDIX_MGA=no
VIDIX_MGA_CRTC2=no
VIDIX_NVIDIA=no
VIDIX_PM2=no
VIDIX_PM3=no
VIDIX_RADEON=no
VIDIX_RAGE128=no
VIDIX_S3=no
VIDIX_SH_VEU=no
VIDIX_SIS=no
VIDIX_UNICHROME=no
VSTREAM = no
WII = no
WIN32DLL = no
WIN32WAVEOUT = auto
WIN32_EMULATION = 
WINVIDIX = 
X11 = no
X264 = no
XANIM_CODECS = yes
XMGA = no
XMMS_PLUGINS = no
XV = no
XVID4 = no
XVIDIX = 
XVMC = no
YUV4MPEG = yes
ZR = no

# FFmpeg
LIBAVUTIL = yes
LIBAVUTIL_A = yes
LIBAVUTIL_SO = auto
LIBAVCODEC = yes
LIBAVCODEC_A = yes
LIBAVCODEC_SO = no
LIBAVFORMAT = yes
LIBAVFORMAT_A = yes
LIBAVFORMAT_SO = auto
LIBPOSTPROC = yes
LIBPOSTPROC_A = yes
LIBPOSTPROC_SO = auto
LIBSWSCALE = yes
LIBSWSCALE_A = yes
LIBSWSCALE_SO = auto

BUILD_STATIC=yes
SRC_PATH=..
BUILD_ROOT=..
LIBPREF=lib
LIBSUF=.a
LIBNAME=$(LIBPREF)$(NAME)$(LIBSUF)

# Some FFmpeg codecs depend on these. Enable them unconditionally for now.
CONFIG_AANDCT=yes
CONFIG_FFT=yes
CONFIG_FFT_MMX=
CONFIG_GOLOMB=yes
CONFIG_MDCT=yes
CONFIG_RDFT=yes

CONFIG_BZLIB=no
CONFIG_ENCODERS=yes
CONFIG_GPL=yes
CONFIG_LIBAMR=
CONFIG_LIBAMR_NB=no
CONFIG_LIBAMR_WB=no
CONFIG_LIBDIRAC=no
CONFIG_LIBFAAC=no
CONFIG_LIBMP3LAME=auto
CONFIG_LIBSCHROEDINGER=no
CONFIG_LIBVORBIS=no
CONFIG_LIBX264=no
CONFIG_LIBXVID=no
CONFIG_MLIB = no
CONFIG_MUXERS=no
CONFIG_POSTPROC = yes
# Prevent building libavcodec/imgresample.c with conflicting symbols
CONFIG_SWSCALE=yes
CONFIG_VDPAU=no
CONFIG_XVMC=no
CONFIG_ZLIB=yes

HAVE_PTHREADS = yes
HAVE_W32THREADS = no
HAVE_YASM = 

CONFIG_AASC_DECODER=yes
CONFIG_AMV_DECODER=yes
CONFIG_ASV1_DECODER=yes
CONFIG_ASV2_DECODER=yes
CONFIG_AVS_DECODER=yes
CONFIG_BETHSOFTVID_DECODER=yes
CONFIG_BFI_DECODER=yes
CONFIG_BMP_DECODER=yes
CONFIG_C93_DECODER=yes
CONFIG_CAVS_DECODER=yes
CONFIG_CINEPAK_DECODER=yes
CONFIG_CLJR_DECODER=yes
CONFIG_CSCD_DECODER=yes
CONFIG_CYUV_DECODER=yes
CONFIG_DNXHD_DECODER=yes
CONFIG_DSICINVIDEO_DECODER=yes
CONFIG_DVVIDEO_DECODER=yes
CONFIG_DXA_DECODER=yes
CONFIG_EACMV_DECODER=yes
CONFIG_EATGQ_DECODER=yes
CONFIG_EATGV_DECODER=yes
CONFIG_EATQI_DECODER=yes
CONFIG_EIGHTBPS_DECODER=yes
CONFIG_EIGHTSVX_EXP_DECODER=yes
CONFIG_EIGHTSVX_FIB_DECODER=yes
CONFIG_ESCAPE124_DECODER=yes
CONFIG_FFV1_DECODER=yes
CONFIG_FFVHUFF_DECODER=yes
CONFIG_FLASHSV_DECODER=yes
CONFIG_FLIC_DECODER=yes
CONFIG_FLV_DECODER=yes
CONFIG_FOURXM_DECODER=yes
CONFIG_FRAPS_DECODER=yes
CONFIG_GIF_DECODER=yes
CONFIG_H261_DECODER=yes
CONFIG_H263_DECODER=yes
CONFIG_H263I_DECODER=yes
CONFIG_H264_DECODER=yes
CONFIG_HUFFYUV_DECODER=yes
CONFIG_IDCIN_DECODER=yes
CONFIG_INDEO2_DECODER=yes
CONFIG_INDEO3_DECODER=yes
CONFIG_INTERPLAY_VIDEO_DECODER=yes
CONFIG_JPEGLS_DECODER=yes
CONFIG_KMVC_DECODER=yes
CONFIG_LOCO_DECODER=yes
CONFIG_MDEC_DECODER=yes
CONFIG_MIMIC_DECODER=yes
CONFIG_MJPEG_DECODER=yes
CONFIG_MJPEGB_DECODER=yes
CONFIG_MMVIDEO_DECODER=yes
CONFIG_MOTIONPIXELS_DECODER=yes
CONFIG_MPEG1VIDEO_DECODER=yes
CONFIG_MPEG2VIDEO_DECODER=yes
CONFIG_MPEG4_DECODER=yes
CONFIG_MPEGVIDEO_DECODER=yes
CONFIG_MSMPEG4V1_DECODER=yes
CONFIG_MSMPEG4V2_DECODER=yes
CONFIG_MSMPEG4V3_DECODER=yes
CONFIG_MSRLE_DECODER=yes
CONFIG_MSVIDEO1_DECODER=yes
CONFIG_MSZH_DECODER=yes
CONFIG_NUV_DECODER=yes
CONFIG_PCX_DECODER=yes
CONFIG_PNG_DECODER=yes
CONFIG_PTX_DECODER=yes
CONFIG_QDRAW_DECODER=yes
CONFIG_QPEG_DECODER=yes
CONFIG_QTRLE_DECODER=yes
CONFIG_RAWVIDEO_DECODER=yes
CONFIG_RL2_DECODER=yes
CONFIG_ROQ_DECODER=yes
CONFIG_RPZA_DECODER=yes
CONFIG_RV10_DECODER=yes
CONFIG_RV20_DECODER=yes
CONFIG_RV30_DECODER=yes
CONFIG_RV40_DECODER=yes
CONFIG_SGI_DECODER=yes
CONFIG_SMACKER_DECODER=yes
CONFIG_SMC_DECODER=yes
CONFIG_SNOW_DECODER=yes
CONFIG_SP5X_DECODER=yes
CONFIG_SUNRAST_DECODER=yes
CONFIG_SVQ1_DECODER=yes
CONFIG_SVQ3_DECODER=yes
CONFIG_TARGA_DECODER=yes
CONFIG_THEORA_DECODER=yes
CONFIG_THP_DECODER=yes
CONFIG_TIERTEXSEQVIDEO_DECODER=yes
CONFIG_TIFF_DECODER=yes
CONFIG_TRUEMOTION1_DECODER=yes
CONFIG_TRUEMOTION2_DECODER=yes
CONFIG_TSCC_DECODER=yes
CONFIG_TXD_DECODER=yes
CONFIG_ULTI_DECODER=yes
CONFIG_VB_DECODER=yes
CONFIG_VC1_DECODER=yes
CONFIG_VCR1_DECODER=yes
CONFIG_VMDVIDEO_DECODER=yes
CONFIG_VMNC_DECODER=yes
CONFIG_VP3_DECODER=yes
CONFIG_VP5_DECODER=yes
CONFIG_VP6_DECODER=yes
CONFIG_VP6A_DECODER=yes
CONFIG_VP6F_DECODER=yes
CONFIG_VQA_DECODER=yes
CONFIG_WMV1_DECODER=yes
CONFIG_WMV2_DECODER=yes
CONFIG_WMV3_DECODER=yes
CONFIG_WNV1_DECODER=yes
CONFIG_XAN_WC3_DECODER=yes
CONFIG_XL_DECODER=yes
CONFIG_ZLIB_DECODER=yes
CONFIG_ZMBV_DECODER=yes
CONFIG_AAC_DECODER=yes
CONFIG_AC3_DECODER=yes
CONFIG_ALAC_DECODER=yes
CONFIG_APE_DECODER=yes
CONFIG_ATRAC3_DECODER=yes
CONFIG_COOK_DECODER=yes
CONFIG_DCA_DECODER=yes
CONFIG_DSICINAUDIO_DECODER=yes
CONFIG_EAC3_DECODER=yes
CONFIG_FLAC_DECODER=yes
CONFIG_IMC_DECODER=yes
CONFIG_MACE3_DECODER=yes
CONFIG_MACE6_DECODER=yes
CONFIG_MLP_DECODER=yes
CONFIG_MP1_DECODER=yes
CONFIG_MP2_DECODER=yes
CONFIG_MP3_DECODER=yes
CONFIG_MP3ADU_DECODER=yes
CONFIG_MP3ON4_DECODER=yes
CONFIG_MPC7_DECODER=yes
CONFIG_MPC8_DECODER=yes
CONFIG_NELLYMOSER_DECODER=yes
CONFIG_QCELP_DECODER=yes
CONFIG_QDM2_DECODER=yes
CONFIG_RA_144_DECODER=yes
CONFIG_RA_288_DECODER=yes
CONFIG_SHORTEN_DECODER=yes
CONFIG_SMACKAUD_DECODER=yes
CONFIG_SONIC_DECODER=yes
CONFIG_TRUESPEECH_DECODER=yes
CONFIG_TTA_DECODER=yes
CONFIG_VMDAUDIO_DECODER=yes
CONFIG_VORBIS_DECODER=yes
CONFIG_WAVPACK_DECODER=yes
CONFIG_WMAV1_DECODER=yes
CONFIG_WMAV2_DECODER=yes
CONFIG_WS_SND1_DECODER=yes
CONFIG_PCM_ALAW_DECODER=yes
CONFIG_PCM_DVD_DECODER=yes
CONFIG_PCM_F32BE_DECODER=yes
CONFIG_PCM_F32LE_DECODER=yes
CONFIG_PCM_F64BE_DECODER=yes
CONFIG_PCM_F64LE_DECODER=yes
CONFIG_PCM_MULAW_DECODER=yes
CONFIG_PCM_S8_DECODER=yes
CONFIG_PCM_S16BE_DECODER=yes
CONFIG_PCM_S16LE_DECODER=yes
CONFIG_PCM_S16LE_PLANAR_DECODER=yes
CONFIG_PCM_S24BE_DECODER=yes
CONFIG_PCM_S24DAUD_DECODER=yes
CONFIG_PCM_S24LE_DECODER=yes
CONFIG_PCM_S32BE_DECODER=yes
CONFIG_PCM_S32LE_DECODER=yes
CONFIG_PCM_U8_DECODER=yes
CONFIG_PCM_U16BE_DECODER=yes
CONFIG_PCM_U16LE_DECODER=yes
CONFIG_PCM_U24BE_DECODER=yes
CONFIG_PCM_U24LE_DECODER=yes
CONFIG_PCM_U32BE_DECODER=yes
CONFIG_PCM_U32LE_DECODER=yes
CONFIG_PCM_ZORK_DECODER=yes
CONFIG_INTERPLAY_DPCM_DECODER=yes
CONFIG_ROQ_DPCM_DECODER=yes
CONFIG_SOL_DPCM_DECODER=yes
CONFIG_XAN_DPCM_DECODER=yes
CONFIG_ADPCM_4XM_DECODER=yes
CONFIG_ADPCM_ADX_DECODER=yes
CONFIG_ADPCM_CT_DECODER=yes
CONFIG_ADPCM_EA_DECODER=yes
CONFIG_ADPCM_EA_MAXIS_XA_DECODER=yes
CONFIG_ADPCM_EA_R1_DECODER=yes
CONFIG_ADPCM_EA_R2_DECODER=yes
CONFIG_ADPCM_EA_R3_DECODER=yes
CONFIG_ADPCM_EA_XAS_DECODER=yes
CONFIG_ADPCM_G726_DECODER=yes
CONFIG_ADPCM_IMA_AMV_DECODER=yes
CONFIG_ADPCM_IMA_DK3_DECODER=yes
CONFIG_ADPCM_IMA_DK4_DECODER=yes
CONFIG_ADPCM_IMA_EA_EACS_DECODER=yes
CONFIG_ADPCM_IMA_EA_SEAD_DECODER=yes
CONFIG_ADPCM_IMA_ISS_DECODER=yes
CONFIG_ADPCM_IMA_QT_DECODER=yes
CONFIG_ADPCM_IMA_SMJPEG_DECODER=yes
CONFIG_ADPCM_IMA_WAV_DECODER=yes
CONFIG_ADPCM_IMA_WS_DECODER=yes
CONFIG_ADPCM_MS_DECODER=yes
CONFIG_ADPCM_SBPRO_2_DECODER=yes
CONFIG_ADPCM_SBPRO_3_DECODER=yes
CONFIG_ADPCM_SBPRO_4_DECODER=yes
CONFIG_ADPCM_SWF_DECODER=yes
CONFIG_ADPCM_THP_DECODER=yes
CONFIG_ADPCM_XA_DECODER=yes
CONFIG_ADPCM_YAMAHA_DECODER=yes
CONFIG_DVBSUB_DECODER=yes
CONFIG_DVDSUB_DECODER=yes
CONFIG_XSUB_DECODER=yes
CONFIG_MPEG1VIDEO_ENCODER=yes
CONFIG_SNOW_ENCODER=yes
CONFIG_PNG_ENCODER=yes
CONFIG_AAC_PARSER=yes
CONFIG_AC3_PARSER=yes
CONFIG_CAVSVIDEO_PARSER=yes
CONFIG_DCA_PARSER=yes
CONFIG_DIRAC_PARSER=yes
CONFIG_DNXHD_PARSER=yes
CONFIG_DVBSUB_PARSER=yes
CONFIG_DVDSUB_PARSER=yes
CONFIG_H261_PARSER=yes
CONFIG_H263_PARSER=yes
CONFIG_H264_PARSER=yes
CONFIG_MJPEG_PARSER=yes
CONFIG_MLP_PARSER=yes
CONFIG_MPEG4VIDEO_PARSER=yes
CONFIG_MPEGAUDIO_PARSER=yes
CONFIG_MPEGVIDEO_PARSER=yes
CONFIG_PNM_PARSER=yes
CONFIG_VC1_PARSER=yes
CONFIG_VP3_PARSER=yes
CONFIG_AAC_DEMUXER=yes
CONFIG_AC3_DEMUXER=yes
CONFIG_AIFF_DEMUXER=yes
CONFIG_AMR_DEMUXER=yes
CONFIG_APC_DEMUXER=yes
CONFIG_APE_DEMUXER=yes
CONFIG_ASF_DEMUXER=yes
CONFIG_ASS_DEMUXER=yes
CONFIG_AU_DEMUXER=yes
CONFIG_AVI_DEMUXER=yes
CONFIG_AVS_DEMUXER=yes
CONFIG_BETHSOFTVID_DEMUXER=yes
CONFIG_BFI_DEMUXER=yes
CONFIG_C93_DEMUXER=yes
CONFIG_CAVSVIDEO_DEMUXER=yes
CONFIG_DAUD_DEMUXER=yes
CONFIG_DIRAC_DEMUXER=yes
CONFIG_DNXHD_DEMUXER=yes
CONFIG_DSICIN_DEMUXER=yes
CONFIG_DTS_DEMUXER=yes
CONFIG_DV_DEMUXER=yes
CONFIG_DXA_DEMUXER=yes
CONFIG_EA_DEMUXER=yes
CONFIG_EA_CDATA_DEMUXER=yes
CONFIG_EAC3_DEMUXER=yes
CONFIG_FFM_DEMUXER=yes
CONFIG_FLAC_DEMUXER=yes
CONFIG_FLIC_DEMUXER=yes
CONFIG_FLV_DEMUXER=yes
CONFIG_FOURXM_DEMUXER=yes
CONFIG_GSM_DEMUXER=yes
CONFIG_GXF_DEMUXER=yes
CONFIG_H261_DEMUXER=yes
CONFIG_H263_DEMUXER=yes
CONFIG_H264_DEMUXER=yes
CONFIG_IDCIN_DEMUXER=yes
CONFIG_IFF_DEMUXER=yes
CONFIG_IMAGE2_DEMUXER=yes
CONFIG_IMAGE2PIPE_DEMUXER=yes
CONFIG_INGENIENT_DEMUXER=yes
CONFIG_IPMOVIE_DEMUXER=yes
CONFIG_ISS_DEMUXER=yes
CONFIG_LMLM4_DEMUXER=yes
CONFIG_M4V_DEMUXER=yes
CONFIG_MATROSKA_DEMUXER=yes
CONFIG_MJPEG_DEMUXER=yes
CONFIG_MLP_DEMUXER=yes
CONFIG_MM_DEMUXER=yes
CONFIG_MMF_DEMUXER=yes
CONFIG_MOV_DEMUXER=yes
CONFIG_MP3_DEMUXER=yes
CONFIG_MPC_DEMUXER=yes
CONFIG_MPC8_DEMUXER=yes
CONFIG_MPEGPS_DEMUXER=yes
CONFIG_MPEGTS_DEMUXER=yes
CONFIG_MPEGTSRAW_DEMUXER=yes
CONFIG_MPEGVIDEO_DEMUXER=yes
CONFIG_MSNWC_TCP_DEMUXER=yes
CONFIG_MTV_DEMUXER=yes
CONFIG_MVI_DEMUXER=yes
CONFIG_MXF_DEMUXER=yes
CONFIG_NC_DEMUXER=yes
CONFIG_NSV_DEMUXER=yes
CONFIG_NUT_DEMUXER=yes
CONFIG_NUV_DEMUXER=yes
CONFIG_OGG_DEMUXER=yes
CONFIG_OMA_DEMUXER=yes
CONFIG_PCM_ALAW_DEMUXER=yes
CONFIG_PCM_MULAW_DEMUXER=yes
CONFIG_PCM_F64BE_DEMUXER=yes
CONFIG_PCM_F64LE_DEMUXER=yes
CONFIG_PCM_F32BE_DEMUXER=yes
CONFIG_PCM_F32LE_DEMUXER=yes
CONFIG_PCM_S32BE_DEMUXER=yes
CONFIG_PCM_S32LE_DEMUXER=yes
CONFIG_PCM_S24BE_DEMUXER=yes
CONFIG_PCM_S24LE_DEMUXER=yes
CONFIG_PCM_S16BE_DEMUXER=yes
CONFIG_PCM_S16LE_DEMUXER=yes
CONFIG_PCM_S8_DEMUXER=yes
CONFIG_PCM_U32BE_DEMUXER=yes
CONFIG_PCM_U32LE_DEMUXER=yes
CONFIG_PCM_U24BE_DEMUXER=yes
CONFIG_PCM_U24LE_DEMUXER=yes
CONFIG_PCM_U16BE_DEMUXER=yes
CONFIG_PCM_U16LE_DEMUXER=yes
CONFIG_PCM_U8_DEMUXER=yes
CONFIG_PVA_DEMUXER=yes
CONFIG_R3D_DEMUXER=yes
CONFIG_RAWVIDEO_DEMUXER=yes
CONFIG_RL2_DEMUXER=yes
CONFIG_RM_DEMUXER=yes
CONFIG_ROQ_DEMUXER=yes
CONFIG_RPL_DEMUXER=yes
CONFIG_SEGAFILM_DEMUXER=yes
CONFIG_SHORTEN_DEMUXER=yes
CONFIG_SIFF_DEMUXER=yes
CONFIG_SMACKER_DEMUXER=yes
CONFIG_SOL_DEMUXER=yes
CONFIG_STR_DEMUXER=yes
CONFIG_SWF_DEMUXER=yes
CONFIG_THP_DEMUXER=yes
CONFIG_TIERTEXSEQ_DEMUXER=yes
CONFIG_TTA_DEMUXER=yes
CONFIG_TXD_DEMUXER=yes
CONFIG_VC1_DEMUXER=yes
CONFIG_VC1T_DEMUXER=yes
CONFIG_VMD_DEMUXER=yes
CONFIG_VOC_DEMUXER=yes
CONFIG_WAV_DEMUXER=yes
CONFIG_WC3_DEMUXER=yes
CONFIG_WSAUD_DEMUXER=yes
CONFIG_WSVQA_DEMUXER=yes
CONFIG_WV_DEMUXER=yes
CONFIG_XA_DEMUXER=yes
CONFIG_YUV4MPEGPIPE_DEMUXER=yes
CONFIG_=yes
CONFIG_DUMP_EXTRADATA_BSF=yes
CONFIG_H264_MP4TOANNEXB_BSF=yes
CONFIG_IMX_DUMP_HEADER_BSF=yes
CONFIG_MJPEGA_DUMP_HEADER_BSF=yes
CONFIG_MP3_HEADER_COMPRESS_BSF=yes
CONFIG_MP3_HEADER_DECOMPRESS_BSF=yes
CONFIG_MOV2TEXTSUB_BSF=yes
CONFIG_NOISE_BSF=yes
CONFIG_REMOVE_EXTRADATA_BSF=yes
CONFIG_TEXT2MOVSUB_BSF=yes
