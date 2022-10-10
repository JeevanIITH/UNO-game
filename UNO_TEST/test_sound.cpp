#include "test_sound.h"

TEST_SOUND::TEST_SOUND()
{


}

TEST_SOUND::~TEST_SOUND()
{

}

//initilisize audio system , load audio files.
void TEST_SOUND::initilisation_1()
{
    soundclass* sd=sd->getinstance();

    //testing init audio with correct audio configs
    int audio_rate = 22050;
    Uint16 audio_format = AUDIO_S16SYS;

    int audio_channels = 2;
    int audio_buffers = 4096;
    QVERIFY(Mix_OpenAudio(audio_rate, MIX_DEFAULT_FORMAT, audio_channels, audio_buffers)==0);


}

void TEST_SOUND::delete_sounds()
{
    soundclass* sd=sd->getinstance();
    sd->delete_all();
    //checking soundclass* instance ==  nullptr
    QVERIFY(!(sd->instance_status()));
}

void TEST_SOUND::check_lists()
{
    soundclass* sd=sd->getinstance();
    QCOMPARE(sd->give_size_of_music(),1);
    QCOMPARE(sd->give_size_of_effects(),2);



}
