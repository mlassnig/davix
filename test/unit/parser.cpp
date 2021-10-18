#include <davix.hpp>
#include <fileops/httpiovec.hpp>
#include <fileops/fileutils.hpp>
#include <gtest/gtest.h>

using namespace Davix;


char normal_vector_range_cstr[]  = "2894597227-2894599011,2894600789-2894601667,2894616262-2894617140,2894619865-2894623464,2906287380-2906491436,2907014445-2907025728,2907228889-2907232035,2913226796-2913239685,2913337799-2913538354,"
        "2920341488-2920341660,2920376486-2920376595,2920377869-2920377987,2920398615-2920398721,2920400327-2920400537,2920407068-2920407263,2920534929-2920547408,2921309945-2921313091,2921314945-2921315052,2921353972-29"
        "21354079,2921355415-2921355519,2921381888-2921382006,2921385811-2921385927,2921386275-2921386384,2923832488-2923835417,2923842762-2923845463,2924345912-2924347518,2924350009-2924351321,2924382902-2924383512,2924"
        "429449-2924432057,2924516324-2924530870,2924556078-2924561911,2924634939-2924667831,2924698529-2924708631,2924718737-2924738719,2924778907-2924800458,2924878902-2924889766,2924898497-2924907906,2925060054-292507"
        "1537,2925082948-2925094376,2925120965-2925136938,2925148273-2925158039,2925178780-2925189684,2925374210-2925385276,2925801184-2925810640,2925970960-2926032309,2926283634-2926317832,2926329105-2926340581,29265320"
        "22-2926541735,2926546946-2926552967,2926597986-2926610425,2926638816-2926644264,2926651300-2926658488,2926813925-2926848245,2927386412-2927397410,2933217130-2933259050,2933262387-2933302854,2933329834-2933334347"
        ",2933338835-2933343477,2933349022-2933358181,2933365316-2933466065,2933626155-2933770574,2933848103-2933862205,2933917894-2933955396,2934057518-2934258138,2935669360-2935844362,2935849059-2935877127,2935879476-2"
        "935885804,2935908849-2935941795,2935944191-2936003068,2936005415-2936088351,2936197558-2936205691,2936213456-2936221551,2936225112-2936228755,2936247929-2936256670,2936263673-2936280963,2940282303-2940294386,294"
        "4698750-2945205175,2945396985-2945397107,2945766398-2945766731,2945775515-2945780462,2946147455-2946150395,2946230445-2946234636,2946241098-2946252531,2946282324-2946298429,2946436685-2946452956,2946532686-29465"
        "36848,2946641704-2946673847,2946760945-2946793165,2946920499-2946924499,2947274177-2947275056,2947277728-2947279512,2947281290-2947282168,2947296763-2947297641,2947300366-2947303965,2958286340-2958492725,2959848059-2959860798"
        ",2959958124-2959961270,2966061833-2966074209,2966170876-2966372789,2973222698-2973222869,2973257655-2973257764,2973259043-2973259152,2973279662-2973279768,2973281374-2973281589,2973288114-2973288312,2973318356-2973328837,2973425694-2973428840,"
        "2976471316-2976474220,2976481466-2976484169,2976983761-2976985381,2976987860-2976989172,2977019939-2977020545,2977064174-2977066750,2977146792-2977160755,2977185134-2977190682,2977262055-2977293837,2977323593-2977333439,"
        "2977343224-2977362718,2977401793-2977422570,2977498630-2977509169,2977517744-2977526878,2977675930-2977687013,2977698033-2977709079,2977734868-2977750346,2977761310-2977770807,2977790863-2977801395,2977978772-2977989474,2978389575-2978398709,"
        "2978552485-2978610681,2978850242-2978883265,2978894197-2978905293,2979090337-2979099769,2979104869-2979110654,2979154473-2979166708,2979194475-2979199737,2979206487-2979213303,2979363203-2979396434,2979916534-2979927163,2985820683-2985863430,2985866696-2985907937,2985935195-2985939801,2985944387-2985949123,2985954606-2985963642,2985970585-2986073297,2986244661-2986391877,2986471584-2986486117,2986542589-2986580155,2986682014-2986886459,2988278869-2988447401,2988452088-2988479695,2988482035-2988488170,2988510304-2988542091,2988544463-2988601553,2988603898-2988684202,2988788984-2988796734,2988804177-2988811923,2988815352-2988818817,2988837573-2988845953,2988852643-2988869416,2992871574-2992883478,2996506775-2996965110,2997190827-2997190949,2997548560-2997548924,2997557956-2997563036,2997937427-2997941053,2998021650-2998025988,2998032525-2998044002,2998073943-2998090372,2998232114-2998248632,2998327934-2998332159,2998438036-2998470383,2998558645-2998591384,2998720455-2998724414,2999082210-2999083089,2999085761-2999087545,2999089323-2999090201,2999104796-2999105674,2999108399-2999111998, 2694452992-2694465611,2746390592-2746402250,2798560058-2798571419,2804195110-2804400838,2805751552-2805762858,2805859068-2805862214,2811940340-2811950464,2812046764-2812251087,2813703640-2813703814,"
        "2819114229-2819114338,2819115652-2819115761,2819136413-2819136519,2819138125-2819138337,2819144814-2819145015,2819174973-2819186728,2819283826-2819286972,2819288838-2819288945,2819327826-2819327933,2819329269-28"
        "19329373,2819355743-2819355871,2819359717-2819359834,2819360180-2819360297,2821830034-2821832958,2821840349-2821843110,2822362368-2822363981,2822366454-2822367777,2822397860-2822398458,2822440809-2822443382,2822"
        "521209-2822534994,2822558999-2822564556,2822635102-2822666100,2822695336-2822705027,2822714640-2822733567,2822771618-2822791908,2822866132-2822876379,2822884625-2822893492,2823041407-2823052245,2823062999-282307"
        "3783,2823098969-2823114083,2823124792-2823134031,2823153653-2823163909,2823338124-2823348557,2823738948-2823747837,2823898889-2823955268,2824190305-2824222631,2824233317-2824244161,2824425048-2824434424,28244394"
        "86-2824445166,2824488577-2824500792,2824528659-2824533870,2824540565-2824547393,2824694274-2824726649,2825235071-2825245434,2831022985-2831065125,2831068370-2831108767,2831135652-2831140188,2831144741-2831149437"
        ",2831154915-2831163895,2831170853-2831272511,2831440783-2831586337,2831665263-2831679584,2831735448-2831773114,2831873965-2832075890,2833445981-2833611751,2833616420-2833643532,2833645857-2833651889,2833673852-2"
        "833705305,2833707683-2833764157,2833766480-2833845088,2833947916-2833955670,2833963034-2833970747,2833974199-2833977678,2833996116-2834004435,2834011055-2834027584,2837963479-2837975148,2841911291-2842391545,284"
        "2581999-2842582121,2842937329-2842937678,2842946394-2842951289,2843325409-2843329045,2843408591-2843412887,2843419493-2843431179,2843461534-2843478329,2843621898-2843638611,2843718479-2843722767,2843830205-28438"
        "63003,2843952215-2843985337,2844117237-2844121570,2844474125-2844475004,2844477676-2844479460,2844481238-2844482116,2844496711-2844497589,2844500314-2844503913,2849752576-2849764487,2855338133-2855542823,2856891"
        "989-2856907940,2863121983-2863135646,2863232633-2863431065,2864879845-2864880018,2864915167-2864915280,2864916579-2864916688,2864937365-2864937471,2864939077-2864939290,2864945837-2864946035,2870336419-287035218"
        "1,2870354035-2870354142,2870393010-2870393117,2870394453-2870394557,2870420895-2870421012";


char singular_vector_range_cstr[] = "2894597227-2894599011,2894600789-2894601667,2894616262-2894617140,2894619865-2894623464,2906287380-2906491436,2907014445-2907025728,2907228889-2907232035,2913226796-2913239685,2913337799-2913538354,"
        "2920341488-2920341660,2920376486-2920376595,2920377869-2920377987,2920398615-2920398721,2920400327-2920400537,2920407068-2920407263,2920534929-2920547408,2921309945-2921313091,2921314945-2921315052,2921353972-29"
        "21354079,2921355415-2921355519,2921381888-2921382006,2921385811-2921385927,2921386275-2921386384,2923832488-2923835417,2923842762-2923845463,2924345912-2924347518,2924350009-2924351321,2924382902-2924383512,2924"
        "429449-2924432057,2924516324-2924530870,2924556078-2924561911,2924634939-2924667831,2924698529-2924708631,2924718737-2924738719,2924778907-2924800458,2924878902-2924889766,2924898497-2924907906,2925060054-292507"
        "1537,2925082948-2925094376,2925120965-2925136938,2925148273-2925158039,2925178780-2925189684,2925374210-2925385276,2925801184-2925810640,2925970960-2926032309,2926283634-2926317832,2926329105-2926340581,29265320"
        "22-2926541735,2926546946-2926552967,2926597986-2926610425,2926638816-2926644264,2926651300-2926658488,2926813925-2926848245,2927386412-2927397410,2933217130-2933259050,2933262387-2933302854,2933329834-2933334347"
        ",2933338835-2933343477,2933349022-2933358181,2933365316-2933466065,2933626155-2933770574,2933848103-2933862205,2933917894-2933955396,2934057518-2934258138,2935669360-2935844362,2935849059-2935877127,2935879476-2"
        "935885804,2935908849-2935941795,2935944191-2936003068,2936005415-2936088351,2936197558-2936205691,2936213456-2936221551,2936225112-2936228755,2936247929-2936256670,2936263673-2936280963,2940282303-2940294386,294"
        "4698750-2945205175,2945396985-2945397107,2945766398-2945766731,2945775515-2945780462,2946147455-2946150395,2946230445-2946234636,2946241098-2946252531,2946282324-2946298429,2946436685-2946452956,2946532686-29465"
        "36848,2946641704-2946673847,2946760945-2946793165,2946920499-2946924499,2947274177-2947275056,2947277728-2947279512,2947281290-2947282168,2947296763-2947297641,2947300366-2947303965,2958286340-2958492725,2959848059-2959860798"
        ",2959958124-2959961270,2966061833-2966074209,2966170876-2966372789,2973222698-2973222869,2973257655-2973257764,2973259043-2973259152,2973279662-2973279768,2973281374-2973281589,2973288114-2973288312,2973318356-2973328837,2973425694-2973428840,"
        "2976471316-2976474220,2976481466-2976484169,2976983761-2976985381,2976987860-2976989172,2977019939-2977020545,2977064174-2977066750,2977146792-2977160755,2977185134-2977190682,2977262055-2977293837,2977323593-2977333439,"
        "2977343224-2977362718,2977401793-2977422570,2977498630-2977509169,2977517744-2977526878,2977675930-2977687013,2977698033-2977709079,2977734868-2977750346,2977761310-2977770807,2977790863-2977801395,2977978772-2977989474,2978389575-2978398709,"
        "2978552485-2978610681,2978850242-2978883265,2978894197-2978905293,2979090337-2979099769,2979104869-2979110654,2979154473-2979166708,2979194475-2979199737,2979206487-2979213303,2979363203-2979396434,2979916534-2979927163,2985820683-2985863430,2985866696-2985907937,2985935195-2985939801,2985944387-2985949123,2985954606-2985963642,2985970585-2986073297,2986244661-2986391877,2986471584-2986486117,2986542589-2986580155,2986682014-2986886459,2988278869-2988447401,2988452088-2988479695,2988482035-2988488170,2988510304-2988542091,2988544463-2988601553,2988603898-2988684202,2988788984-2988796734,2988804177-2988811923,2988815352-2988818817,2988837573-2988845953,2988852643-2988869416,2992871574-2992883478,2996506775-2996965110,2997190827-2997190949,2997548560-2997548924,2997557956-2997563036,2997937427-2997941053,2998021650-2998025988,2998032525-2998044002,2998073943-2998090372,2998232114-2998248632,2998327934-2998332159,2998438036-2998470383,2998558645-2998591384,2998720455-2998724414,2999082210-2999083089,2999085761-2999087545,2999089323-2999090201,2999104796-2999105674,2999108399-2999111998, 2694452992-2694465611,2746390592-2746402250,2798560058-2798571419,2804195110-2804400838,2805751552-2805762858,2805859068-2805862214,2811940340-2811950464,2812046764-2812251087,2813703640-2813703814,"
        "2819114229-2819114338,2819115652-2819115761,2819136413-2819136519,2819138125-2819138337,2819144814-2819145015,2819174973-2819186728,2819283826-2819286972,2819288838-2819288945,2819327826-2819327933,2819329269-28"
        "19329373,2819355743-2819355871,2819359717-2819359834,2819360180-2819360297,2821830034-2821832958,2821840349-2821843110,2822362368-2822363981,2822366454-2822367777,2822397860-2822398458,2822440809-2822443382,2822"
        "521209-2822534994,2822558999-2822564556,2822635102-2822666100,2822695336-2822705027,2822714640-2822733567,2822771618-2822791908,2822866132-2822876379,2822884625-2822893492,2823041407-2823052245,2823062999-282307"
        "3783,2823098969-2823114083,2823124792-2823134031,2823153653-2823163909,2823338124-2823348557,2823738948-2823747837,2823898889-2823955268,2824190305-2824222631,2824233317-2824244161,2824425048-2824434424,28244394"
        "86-2824445166,2824488577-2824500792,2824528659-2824533870,2824540565-2824547393,2824694274-2824726649,2825235071-2825245434,2831022985-2831065125,2831068370-2831108767,2831135652-2831140188,2831144741-2831149437"
        ",2831154915-2831163895,2831170853-2831272511,2831440783-2831586337,2831665263-2831679584,2831735448-2831773114,2831873965-2832075890,2833445981-2833611751,2833616420-2833643532,2833645857-2833651889,2833673852-2"
        "833705305,2833707683-2833764157,2833766480-2833845088,2833947916-2833955670,2833963034-2833970747,2833974199-2833977678,2833996116-2834004435,2834011055-2834027584,2837963479-2837975148,2841911291-2842391545,284"
        "2581999-2842582121,2842937329-2842937678,2842946394-2842951289,2843325409-2843329045,2843408591-2843412887,2843419493-2843431179,2843461534-2843478329,2843621898-2843638611,2843718479-2843722767,2843830205-28438"
        "63003,2843952215-2843985337,2844117237-2844121570,2844474125-2844475004,2844477676-2844479460,2844481238-2844482116,2844496711-2844497589,2844500314-2844503913,2849752576-2849764487,2855338133-2855542823,2856891"
        "989-2856907940,2863121983-2863135646,2863232633-2863431065,2864879845-2864880018,2864915167-2864915280,2864916579-2864916688,2864937365-2864937471,2864939077-2864939290,2864945837-2864946035,2870336419-287035218"
        "1,2870354035-2870354142,2870393010-2870393117,2870394453-2870394557,2870420895-2870421012,2870424812-2870424933,2870425283-2870425398,2872897076-2872899957,2872907320-2872910179,2873421207-2873422827,2873425312-"
        "2873426624,2873459902-2873460505,2873501613-2873504138,2873579634-2873593015,2873616270-2873621691,2873690666-2873720736,2873749003-2873758321,2873767613-2873785919,2873822523-2873842126,2873914014-2873923939,28"
        "73932161-2873940985,2874086014-2874096421,2874106823-2874117213,2874141572-2874156207,2874166520-2874175394,2874194283-2874204212,2874372723-2874382807,2874761523-2874770206,2874918539-2874973443,2875202781-2875"
        "234075,2875244393-2875254892,2875429805-2875438930,2875443796-2875449344,2875491430-2875503320,2875530432-2875535526,2875541928-2875548496,2875690125-2875721370,2876213600-2876223621,2881893880-2881936152,288193"
        "9433-2881980116,2882007211-2882011755,2882016296-2882021005,2882026484-2882035590,2882042577-2882144346,2882313188-2882459082,2882537928-2882552213,2882608291-2882645978,2882747765-2882950560,2884257342-28844154"
        "78,2884420113-2884446503,2884448822-2884454634,2884475526-2884505692,2884508048-2884562124,2884564433-2884639476,2884735800-2884743363,2884750668-2884758224,2884761726-2884765245,2884783598-2884791660,2884798311"
        "-2884814319,2888674449-2888686751,2892050274-2892515560,2892708900-2892709022,2893068732-2893069081,2893077811-2893082715,2893451044-2893454294,2893534657-2893538912,2893545469-2893557026,2893587035-2893603411,2"
        "893744017-2893760682,2893840332-2893844616,2893950557-2893982883,2894070929-2894103592,2894232130-2894235963,2894593676-2894594555";

int parse_range(std::istringstream & stream, size_t & n, dav_off_t & begin, dav_off_t & end){
    std::string part;
    char trash;
    if(stream.eof())
            return -1;
    std::getline(stream, part, ',');
    std::istringstream ss(part);
    ss >> begin;
    ss >> trash;
    ss >> end;
    std::cout << "range: " << begin << " " << end << std::endl;
    return ++n;
}


// with this number of element, the result will be exactly 178 *2 = 356 elems
// regression test for LCGUTIL-456
TEST(IOVecMultiPartPaser, generateSingularRangeTest){
    std::string singular_vector_range(singular_vector_range_cstr);
    std::istringstream stream(singular_vector_range);
    size_t n =0;
    OffsetCallback generator_range( std::bind(&parse_range, std::ref(stream), std::ref(n), std::placeholders::_1, std::placeholders::_2));

    std::vector< std::pair<dav_size_t, std::string> > res = generateRangeHeaders(3900, generator_range);
    ASSERT_EQ(356, n);
    ASSERT_EQ(2, res.size());
    for(std::vector<std::pair<dav_size_t, std::string> >::iterator it = res.begin(); it < res.end(); ++it){
        ASSERT_EQ(178, it->first);
        ASSERT_LE(5, it->second.size());
    }
}


// with this number of element, the result will be exactly 178 *2 = 356 elems
// regression test for LCGUTIL-456
TEST(IOVecMultiPartPaser, generateNormalRangeTest){
    std::string singular_vector_range(normal_vector_range_cstr);
    std::istringstream stream(singular_vector_range);
    size_t n =0;
    OffsetCallback generator_range( std::bind(&parse_range, std::ref(stream), std::ref(n), std::placeholders::_1, std::placeholders::_2));

    std::vector< std::pair<dav_size_t, std::string> > res = generateRangeHeaders(3900, generator_range);

    ASSERT_EQ(287, n);
    ASSERT_EQ(2, res.size());
    std::pair<dav_size_t, std::string> e = res.at(0);
    ASSERT_EQ(178, e.first);
    ASSERT_LE(5, e.second.size());
    e = res.at(1);
    ASSERT_EQ(287-178, e.first);
    ASSERT_LE(5, e.second.size());

}



TEST(IOVecMultiPartParser, headerParser){
    std::string header;
    dav_size_t size;
    dav_off_t offset;
    header = "Content-type: application/xml"; // random generic header

    int ret = find_header_params((char*) header.c_str(), header.size(), &size, &offset);
    ASSERT_EQ(ret,0);

    header = "big brother is wathing you";

    ret = find_header_params((char*) header.c_str(), header.size(), &size, &offset);
    ASSERT_EQ(ret,-1);


    header = "Content-Range: bytes 600-900/8000";
    ret = find_header_params((char*) header.c_str(), header.size(), &size, &offset);
    ASSERT_EQ(1,ret);
    ASSERT_EQ(301, size);
    ASSERT_EQ(600, offset);

    header = "conTent-range: bytes 600-900/8000"; // break case
    ret = find_header_params((char*) header.c_str(), header.size(), &size, &offset);
    ASSERT_EQ(1,ret);
    ASSERT_EQ(301, size);
    ASSERT_EQ(600, offset);



    header = "conTent-range: bytes 600ssss-9e00/8000"; // break case
    ret = find_header_params((char*) header.c_str(), header.size(),&size, &offset);
    ASSERT_EQ(ret,-1);

    header = "Content-Range: GalaticCreditStandard 600-900/8000";
    ret = find_header_params((char*) header.c_str(), header.size(), &size, &offset);
    ASSERT_EQ(-1,ret);

}


TEST(IOVecMultiPartParser, BoundaryExtract){
    std::string header, boundary;
    DavixError* tmp_err = NULL;
    header = " multipart/mixed; boundary=gc0p4Jq0M2Yt08jU534c0p";

    int ret = http_extract_boundary_from_content_type(header, boundary, &tmp_err);
    ASSERT_EQ(0,ret );
    ASSERT_STREQ(boundary.c_str(), "gc0p4Jq0M2Yt08jU534c0p");
    ASSERT_EQ(NULL, tmp_err);

    boundary = "";
    header = " multipart/mixed; boundary=";
    ret = http_extract_boundary_from_content_type(header, boundary, &tmp_err);
    ASSERT_EQ(-1,ret );
    DavixError::clearError(&tmp_err);

    boundary = "";
    header = " multipart/mixed; boundary=\"helloworld\"";
    ret = http_extract_boundary_from_content_type(header, boundary, &tmp_err);
    ASSERT_EQ(0,ret );
    ASSERT_STREQ(boundary.c_str(), "helloworld");
    ASSERT_EQ(NULL, tmp_err);


    boundary = "";
    header = " multipart/mixed; boundary=helloworld; some trash strng";
    ret = http_extract_boundary_from_content_type(header, boundary, &tmp_err);
    ASSERT_EQ(0,ret );
    ASSERT_STREQ(boundary.c_str(), "helloworld");
    ASSERT_EQ(NULL, tmp_err);

}

int numb_it=0;

static int callback_offset_stupid(dav_off_t & begin, dav_off_t & end){
    begin = numb_it*1000+100;
    end=numb_it*1000+500;
    numb_it++;
    if(numb_it > 1000)
        return -1;
    return 0;
}

TEST(headerParser, generateRange){
    std::string header;
    const dav_size_t max_header_size = rand()%8000+30;
    OffsetCallback o(callback_offset_stupid);

    std::vector<std::pair<dav_size_t,std::string> >  ranges;
    ranges = generateRangeHeaders(max_header_size, o);
    std::cout << " ranges size " << ranges.size() << std::endl;
    for(std::vector<std::pair<dav_size_t,std::string> > ::iterator it = ranges.begin(); it < ranges.end(); it++){
        ASSERT_LE(it->second.size(), max_header_size+20);
        ASSERT_GE(it->first, 1);

        std::cout << "NRange: " << (*it).first << std::endl;
        std::cout << "Range: " << (*it).second << std::endl;
    }
    ASSERT_LE(2, ranges.size());
}


// URL parser
TEST(UriTests, testRelativeUri){
    Davix::Uri u("http://datagrid.lbl.gov/testdata/R/test01.data");
    std::string proto_rel("//example.org/test"), abs_path("/hello/world/"), rel_path("blabla/test");

    Davix::Uri res = Uri::fromRelativePath(u, proto_rel);
    ASSERT_EQ(StatusCode::OK, res.getStatus());
    ASSERT_STREQ("http://example.org/test", res.getString().c_str());

    res = Uri::fromRelativePath(u, abs_path);
    ASSERT_EQ(StatusCode::OK, res.getStatus());
    ASSERT_STREQ("http://datagrid.lbl.gov/hello/world/", res.getString().c_str());

    res = Uri::fromRelativePath(u, rel_path);
    ASSERT_EQ(StatusCode::OK, res.getStatus());
    ASSERT_STREQ("http://datagrid.lbl.gov/testdata/R/test01.data/blabla/test", res.getString().c_str());

}

TEST(UriTests, addParamWithSlashes) {
    Davix::Uri u("http://datagrid.lbl.gov/testdata/R/test01.data");
    ASSERT_EQ(u.getString(), "http://datagrid.lbl.gov/testdata/R/test01.data");

    u.addQueryParam("test1", "test2");
    u.addQueryParam("test1/with/slashes", "aaa/aaa");
    u.addQueryParam("test1!with?evil*chars", "aaa/aaa");

    ASSERT_EQ(u.getString(), "http://datagrid.lbl.gov/testdata/R/test01.data?test1=test2&test1%2Fwith%2Fslashes=aaa%2Faaa&test1%21with%3Fevil%2Achars=aaa%2Faaa");

    std::string hugeKey, hugeVal;
    hugeKey.resize(8000);
    hugeVal.resize(8000);

    for(uint64_t i = 0; i < 8000; i++) {
        hugeKey[i] = '/';
        hugeVal[i] = '/';
    }

    u.addQueryParam(hugeKey, hugeVal);
}

TEST(UriTests, ips) {
    Davix::Uri u("http://192.168.1.1/testdata/R/test01.data");
    ASSERT_EQ(u.getStatus(), StatusCode::OK);
    ASSERT_EQ(u.getString(), "http://192.168.1.1/testdata/R/test01.data");
    ASSERT_EQ(u.getPort(), 0);
    ASSERT_EQ(u.getHost(), "192.168.1.1");

    u = Davix::Uri("http://192.168.1.1:123/testdata/R/test01.data");
    ASSERT_EQ(u.getStatus(), StatusCode::OK);
    ASSERT_EQ(u.getString(), "http://192.168.1.1:123/testdata/R/test01.data");
    ASSERT_EQ(u.getPort(), 123);
    ASSERT_EQ(u.getHost(), "192.168.1.1");

    u = Davix::Uri("http://[2001:1458:301:a8ae::100:23]:443/testdata/R/test01.data");
    ASSERT_EQ(u.getStatus(), StatusCode::OK);
    ASSERT_EQ(u.getString(), "http://[2001:1458:301:a8ae::100:23]:443/testdata/R/test01.data");
    ASSERT_EQ(u.getPort(), 443);
    ASSERT_EQ(u.getHost(), "[2001:1458:301:a8ae::100:23]");

    u = Davix::Uri("http://[2001:1458:301:a8ae::100:23]/testdata/R/test01.data");
    ASSERT_EQ(u.getStatus(), StatusCode::OK);
    ASSERT_EQ(u.getString(), "http://[2001:1458:301:a8ae::100:23]/testdata/R/test01.data");
    ASSERT_EQ(u.getPort(), 0);
    ASSERT_EQ(u.getHost(), "[2001:1458:301:a8ae::100:23]");
}

TEST(UriTests, password_special_characters) {
    Davix::Uri u("https://username:password@host.ch/data/file");
    ASSERT_EQ(u.getStatus(), StatusCode::OK);
    ASSERT_EQ(u.getString(), "https://username:password@host.ch/data/file");
    ASSERT_EQ(u.getUserInfo(), "username:password");

    u = Davix::Uri("https://username:p\\@ssword@host.ch/data/file");
    ASSERT_EQ(u.getStatus(), StatusCode::OK);
    ASSERT_EQ(u.getString(), "https://username:p\\@ssword@host.ch/data/file");
    ASSERT_EQ(u.getUserInfo(), "username:p%40ssword");

    u = Davix::Uri("https://username:p\\ssw0rd\\:@host.ch/data/file");
    ASSERT_EQ(u.getStatus(), StatusCode::OK);
    ASSERT_EQ(u.getString(), "https://username:p\\ssw0rd\\:@host.ch/data/file");
    ASSERT_EQ(u.getUserInfo(), "username:p\\ssw0rd%3A");

    u = Davix::Uri("https://username:p\\@ssword\\@host.ch/data/file");
    ASSERT_EQ(u.getStatus(), StatusCode::UriParsingError);
}
