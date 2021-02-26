#include "Setup.h"

void Setup::execute()
{
	setupAll();
}

void Setup::setupAll()
{
	setupCore();
	setupSoundBuffers();
	setupFonts();
	setupTextures();
	setupSounds();
	setupMusic();
	setupTexts();
	setupRectangleShapes();
}

void Setup::setupCore()
{
	m_RenderWindow->setFramerateLimit(60);

	*m_RenderLayerCount = 5; // for pong 5 layers is more than enough
	*m_DeltaTime		= DeltaTime();
	*m_Resolution		= sf::Vector2f(m_RenderWindow->getSize().x, m_RenderWindow->getSize().y);
	*m_AspectRatio		= sf::Vector2f(AspectRatioCalculator::GetAspectRatio(*m_Resolution));
	*m_Scale			= sf::Vector2f(ScaleCalculator::GetScale(*m_Resolution, *m_AspectRatio));
	*m_PreviousState	= GAME_STATE::NONE;
	*m_CurrentState		= GAME_STATE::TITLE;
}

void Setup::setupSoundBuffers()
{
	////m_SoundBuffers->get("SoundBufferHit").loadFromFile(		"resource/sounds/pong/.wav"		);
	////m_SoundBuffers->get("SoundBufferScore").loadFromFile(	"resource/sounds/pong/.wav"		);
	////m_SoundBuffers->get("SoundBufferWin").loadFromFile(		"resource/sounds/pong/.wav"		);
	////m_SoundBuffers->get("SoundBufferLose").loadFromFile(	"resource/sounds/pong/.wav"		);
	m_SoundBuffers->get("SoundBufferOK").loadFromFile(		"resource/sounds/pong/ok.wav"	);
	////m_SoundBuffers->get("SoundBufferCancel").loadFromFile(	"resource/sounds/pong/.wav"		);
}

void Setup::setupFonts()
{
	m_Fonts->get("FontMain").loadFromFile("resource/fonts/pong/chess_type.ttf");
}

void Setup::setupTextures()
{
	m_Textures->get("TextureBackground").loadFromFile(		"resource/textures/pong/background.png"	);
	m_Textures->get("TexturePlayerLeft").loadFromFile(		"resource/textures/pong/paddle.png"		);
	m_Textures->get("TexturePlayerRight").loadFromFile(		"resource/textures/pong/paddle.png"		);
	m_Textures->get("TexturePongBall").loadFromFile(		"resource/textures/pong/pong_ball.png"	);
}

void Setup::setupSounds()
{
	////m_Sounds->get("SoundHit").setBuffer(		m_SoundBuffers->get("SoundBufferHit")		);
	////m_Sounds->get("SoundScore").setBuffer(		m_SoundBuffers->get("SoundBufferScore")		);
	////m_Sounds->get("SoundWin").setBuffer(		m_SoundBuffers->get("SoundBufferWin")		);
	////m_Sounds->get("SoundLose").setBuffer(		m_SoundBuffers->get("SoundBufferLose")		);
	m_Sounds->get("SoundOk").setBuffer(			m_SoundBuffers->get("SoundBufferOK")		);
	////m_Sounds->get("SoundCancel").setBuffer(		m_SoundBuffers->get("SoundBufferCancel")	);
}

void Setup::setupMusic()
{
	m_Music->get("MusicAmbient")->openFromFile("resource/music/pong/inner_light.wav"); 
	m_Music->get("MusicAmbient")->play();
}

void Setup::setupTexts()
{
	Font* fontMain = &m_Fonts->get("FontMain");

	m_Texts->get("TextTitleID").setFont(			*fontMain	);
	m_Texts->get("TextTitleVersion").setFont(		*fontMain	);
	m_Texts->get("TextTitlePlay").setFont(			*fontMain	);
	m_Texts->get("TextTitleGameMode").setFont(		*fontMain	);
	m_Texts->get("TextTitleScreenMode").setFont(	*fontMain	);
	m_Texts->get("TextTitleResolution").setFont(	*fontMain	);
	m_Texts->get("TextTitleQuit").setFont(			*fontMain	);
	m_Texts->get("TextTitleDetails").setFont(		*fontMain	);
	m_Texts->get("TextPlayerLeftID").setFont(		*fontMain	);
	m_Texts->get("TextPlayerLeftScore").setFont(	*fontMain	);
	m_Texts->get("TextPlayerLeftRank").setFont(		*fontMain	);
	m_Texts->get("TextPlayerRightID").setFont(		*fontMain	);
	m_Texts->get("TextPlayerRightScore").setFont(	*fontMain	);
	m_Texts->get("TextPlayerRightRank").setFont(	*fontMain	);
	m_Texts->get("TextMessage").setFont(			*fontMain	);
	
	m_Texts->get("TextTitleID").setCharacterSize(			68	);
	m_Texts->get("TextTitleVersion").setCharacterSize(		13	);
	m_Texts->get("TextTitlePlay").setCharacterSize(			16	);
	m_Texts->get("TextTitleGameMode").setCharacterSize(		16	);
	m_Texts->get("TextTitleScreenMode").setCharacterSize(	16	);
	m_Texts->get("TextTitleResolution").setCharacterSize(	16	);
	m_Texts->get("TextTitleQuit").setCharacterSize(			16	);
	m_Texts->get("TextTitleDetails").setCharacterSize(		12	);
	m_Texts->get("TextPlayerLeftID").setCharacterSize(		20	);
	m_Texts->get("TextPlayerLeftScore").setCharacterSize(	20	);
	m_Texts->get("TextPlayerLeftRank").setCharacterSize(	20	);
	m_Texts->get("TextPlayerRightID").setCharacterSize(		20	);
	m_Texts->get("TextPlayerRightScore").setCharacterSize(	20	);
	m_Texts->get("TextPlayerRightRank").setCharacterSize(	20	);
	m_Texts->get("TextMessage").setCharacterSize(			45	);

	m_Texts->get("TextTitleID").setScale(			*m_Scale	);
	m_Texts->get("TextTitleVersion").setScale(		*m_Scale	);
	m_Texts->get("TextTitlePlay").setScale(			*m_Scale	);
	m_Texts->get("TextTitleGameMode").setScale(		*m_Scale	);
	m_Texts->get("TextTitleScreenMode").setScale(	*m_Scale	);
	m_Texts->get("TextTitleResolution").setScale(	*m_Scale	);
	m_Texts->get("TextTitleQuit").setScale(			*m_Scale	);
	m_Texts->get("TextTitleDetails").setScale(		*m_Scale	);
	m_Texts->get("TextPlayerLeftID").setScale(		*m_Scale	);
	m_Texts->get("TextPlayerLeftScore").setScale(	*m_Scale	);
	m_Texts->get("TextPlayerLeftRank").setScale(	*m_Scale	);
	m_Texts->get("TextPlayerRightID").setScale(		*m_Scale	);
	m_Texts->get("TextPlayerRightScore").setScale(	*m_Scale	);
	m_Texts->get("TextPlayerRightRank").setScale(	*m_Scale	);
	m_Texts->get("TextMessage").setScale(			*m_Scale	);

	m_Texts->get("TextTitleID").setLetterSpacing(			2	);
	m_Texts->get("TextTitleVersion").setLetterSpacing(		1	);
	m_Texts->get("TextTitlePlay").setLetterSpacing(			2	);
	m_Texts->get("TextTitleGameMode").setLetterSpacing(		2	);
	m_Texts->get("TextTitleScreenMode").setLetterSpacing(	2	);
	m_Texts->get("TextTitleResolution").setLetterSpacing(	2	);
	m_Texts->get("TextTitleQuit").setLetterSpacing(			2	);
	m_Texts->get("TextTitleDetails").setLetterSpacing(		2	);
	m_Texts->get("TextPlayerLeftID").setLetterSpacing(		2	);
	m_Texts->get("TextPlayerLeftScore").setLetterSpacing(	2	);
	m_Texts->get("TextPlayerLeftRank").setLetterSpacing(	2	);
	m_Texts->get("TextPlayerRightID").setLetterSpacing(		2	);
	m_Texts->get("TextPlayerRightScore").setLetterSpacing(	2	);
	m_Texts->get("TextPlayerRightRank").setLetterSpacing(	2	);
	m_Texts->get("TextMessage").setLetterSpacing(			2	);

	const auto resolutionStringX = std::to_string((int)m_Resolution->x);
	const auto resolutionStringY = std::to_string((int)m_Resolution->y);

	m_Texts->get("TextTitleID").setString(			"Pong Ultimate");
	m_Texts->get("TextTitleVersion").setString(		"0.0.1");
	m_Texts->get("TextTitlePlay").setString(		"Play");
	m_Texts->get("TextTitleGameMode").setString(	"Cpu");
	m_Texts->get("TextTitleScreenMode").setString(	((m_Resolution->x == sf::VideoMode::getDesktopMode().width) && (m_Resolution->y == sf::VideoMode::getDesktopMode().height) ? "Fullscreen" : "Borderless"));
	m_Texts->get("TextTitleResolution").setString(	resolutionStringX + "x" + resolutionStringY);
	m_Texts->get("TextTitleQuit").setString(		"Quit");
	m_Texts->get("TextTitleDetails").setString(		"   powered by SFML API\nDesigned & Programmed by\n       Scott Rivett\n");
	m_Texts->get("TextPlayerLeftID").setString(		"Player Left");
	m_Texts->get("TextPlayerLeftScore").setString(	"Score: 0");
	m_Texts->get("TextPlayerLeftRank").setString(	"Rank: // TO DO");
	m_Texts->get("TextPlayerRightID").setString(	"Player Right");
	m_Texts->get("TextPlayerRightScore").setString(	"Score: 0");
	m_Texts->get("TextPlayerRightRank").setString(	"Rank: // TO DO");
	m_Texts->get("TextMessage").setString(			"Game Starting In...");

	m_Texts->get("TextTitleID").setPosition(			(300	*	m_Scale->x)	,	(14		*	m_Scale->y)		);
	m_Texts->get("TextTitleVersion").setPosition(		(300	*	m_Scale->x)	,	(95		*	m_Scale->y)		);
	m_Texts->get("TextTitlePlay").setPosition(			(617	*	m_Scale->x)	,	(313	*	m_Scale->y)		);
	m_Texts->get("TextTitleGameMode").setPosition(		(621	*	m_Scale->x)	,	(343	*	m_Scale->y)		);
	m_Texts->get("TextTitleScreenMode").setPosition(	(577	*	m_Scale->x)	,	(373	*	m_Scale->y)		);
	m_Texts->get("TextTitleResolution").setPosition(	(588	*	m_Scale->x)	,	(403	*	m_Scale->y)		);
	m_Texts->get("TextTitleQuit").setPosition(			(617	*	m_Scale->x)	,	(433	*	m_Scale->y)		);
	m_Texts->get("TextTitleDetails").setPosition(		(530	*	m_Scale->x)	,	(653	*	m_Scale->y)		);
	m_Texts->get("TextPlayerLeftID").setPosition(		(32		*	m_Scale->x)	,	(27		*	m_Scale->y)		);
	m_Texts->get("TextPlayerLeftScore").setPosition(	(32		*	m_Scale->x)	,	(59		*	m_Scale->y)		);
	m_Texts->get("TextPlayerLeftRank").setPosition(		(32		*	m_Scale->x)	,	(91		*	m_Scale->y)		);
	m_Texts->get("TextPlayerRightID").setPosition(		(1058	*	m_Scale->x)	,	(27		*	m_Scale->y)		);
	m_Texts->get("TextPlayerRightScore").setPosition(	(1130	*	m_Scale->x)	,	(59		*	m_Scale->y)		);
	m_Texts->get("TextPlayerRightRank").setPosition(	(1035	*	m_Scale->x)	,	(91		*	m_Scale->y)		);
	m_Texts->get("TextMessage").setPosition(			(305	*	m_Scale->x)	,	(320	*	m_Scale->y)		);

	m_Texts->get("TextTitleID").setRenderEnabled(			true	);
	m_Texts->get("TextTitleVersion").setRenderEnabled(		true	);
	m_Texts->get("TextTitlePlay").setRenderEnabled(			true	);
	m_Texts->get("TextTitleGameMode").setRenderEnabled(		true	);
	m_Texts->get("TextTitleScreenMode").setRenderEnabled(	true	);
	m_Texts->get("TextTitleResolution").setRenderEnabled(	true	);
	m_Texts->get("TextTitleQuit").setRenderEnabled(			true	);
	m_Texts->get("TextTitleDetails").setRenderEnabled(		true	);
	m_Texts->get("TextPlayerLeftID").setRenderEnabled(		false	);
	m_Texts->get("TextPlayerLeftScore").setRenderEnabled(	false	);
	m_Texts->get("TextPlayerLeftRank").setRenderEnabled(	false	);
	m_Texts->get("TextPlayerRightID").setRenderEnabled(		false	);
	m_Texts->get("TextPlayerRightScore").setRenderEnabled(	false	);
	m_Texts->get("TextPlayerRightRank").setRenderEnabled(	false	);
	m_Texts->get("TextMessage").setRenderEnabled(			false	);

	m_Texts->get("TextTitleID").setRenderLayer(				3	);
	m_Texts->get("TextTitleVersion").setRenderLayer(		3	);
	m_Texts->get("TextTitlePlay").setRenderLayer(			3	);
	m_Texts->get("TextTitleGameMode").setRenderLayer(		3	);
	m_Texts->get("TextTitleScreenMode").setRenderLayer(		3	);
	m_Texts->get("TextTitleResolution").setRenderLayer(		3	);
	m_Texts->get("TextTitleQuit").setRenderLayer(			3	);
	m_Texts->get("TextTitleDetails").setRenderLayer(		3	);
	m_Texts->get("TextPlayerLeftID").setRenderLayer(		3	);
	m_Texts->get("TextPlayerLeftScore").setRenderLayer(		3	);
	m_Texts->get("TextPlayerLeftRank").setRenderLayer(		3	);
	m_Texts->get("TextPlayerRightID").setRenderLayer(		3	);
	m_Texts->get("TextPlayerRightScore").setRenderLayer(	3	);
	m_Texts->get("TextPlayerRightRank").setRenderLayer(		3	);
	m_Texts->get("TextMessage").setRenderLayer(				3	);
}

void Setup::setupRectangleShapes()
{
	m_RectangleShapes->get("Background").setTexture(		&m_Textures->get("TextureBackground")	);
	m_RectangleShapes->get("ButtonPlay").setTexture(		nullptr									);
	m_RectangleShapes->get("ButtonGameMode").setTexture(	nullptr									);
	m_RectangleShapes->get("ButtonScreenMode").setTexture(	nullptr									);
	m_RectangleShapes->get("ButtonResolution").setTexture(	nullptr									);
	m_RectangleShapes->get("ButtonQuit").setTexture(		nullptr									);
	m_RectangleShapes->get("MessageBanner").setTexture(		nullptr									);
	m_RectangleShapes->get("SplashScreen").setTexture(		nullptr									);
	m_RectangleShapes->get("PlayerLeft").setTexture(		&m_Textures->get("TexturePlayerLeft")	);
	m_RectangleShapes->get("PlayerRight").setTexture(		&m_Textures->get("TexturePlayerRight")	);
	m_RectangleShapes->get("PongBall").setTexture(			&m_Textures->get("TexturePongBall")		);


	m_RectangleShapes->get("Background").setSize(		sf::Vector2f(	*m_Resolution									)	);
	m_RectangleShapes->get("ButtonPlay").setSize(		sf::Vector2f(	m_Resolution->x		,	25						)	);
	m_RectangleShapes->get("ButtonGameMode").setSize(	sf::Vector2f(	m_Resolution->x		,	25						)	);
	m_RectangleShapes->get("ButtonScreenMode").setSize(	sf::Vector2f(	m_Resolution->x		,	25						)	);
	m_RectangleShapes->get("ButtonResolution").setSize(	sf::Vector2f(	m_Resolution->x		,	25						)	);
	m_RectangleShapes->get("ButtonQuit").setSize(		sf::Vector2f(	m_Resolution->x		,	25						)	);
	m_RectangleShapes->get("MessageBanner").setSize(	sf::Vector2f(	m_Resolution->x		,	100						)	);
	m_RectangleShapes->get("SplashScreen").setSize(		sf::Vector2f(	*m_Resolution									)	);
	m_RectangleShapes->get("PlayerLeft").setSize(		sf::Vector2f(	m_Textures->get("TexturePlayerLeft").getSize()	)	);
	m_RectangleShapes->get("PlayerRight").setSize(		sf::Vector2f(	m_Textures->get("TexturePlayerRight").getSize()	)	);
	m_RectangleShapes->get("PongBall").setSize(			sf::Vector2f(	m_Textures->get("TexturePongBall").getSize()	)	);

	m_RectangleShapes->get("Background").setOrigin(			sf::Vector2f(	0														,	0															)	);
	m_RectangleShapes->get("ButtonPlay").setOrigin(			sf::Vector2f(	0														,	0															)	);
	m_RectangleShapes->get("ButtonGameMode").setOrigin(		sf::Vector2f(	0														,	0															)	);
	m_RectangleShapes->get("ButtonScreenMode").setOrigin(	sf::Vector2f(	0														,	0															)	);
	m_RectangleShapes->get("ButtonResolution").setOrigin(	sf::Vector2f(	0														,	0															)	);
	m_RectangleShapes->get("ButtonQuit").setOrigin(			sf::Vector2f(	0														,	0															)	);
	m_RectangleShapes->get("MessageBanner").setOrigin(		sf::Vector2f(	0														,	0															)	);
	m_RectangleShapes->get("SplashScreen").setOrigin(		sf::Vector2f(	0														,	0															)	);
	m_RectangleShapes->get("PlayerLeft").setOrigin(			sf::Vector2f(	m_Textures->get("TexturePlayerLeft").getSize().x	/ 2	,	m_Textures->get("TexturePlayerLeft").getSize().y	/ 2		)	);
	m_RectangleShapes->get("PlayerRight").setOrigin(		sf::Vector2f(	m_Textures->get("TexturePlayerRight").getSize().x	/ 2	,	m_Textures->get("TexturePlayerRight").getSize().y	/ 2		)	);
	m_RectangleShapes->get("PongBall").setOrigin(			sf::Vector2f(	m_Textures->get("TexturePongBall").getSize().x		/ 2	,	m_Textures->get("TexturePongBall").getSize().y		/ 2		)	);

	m_RectangleShapes->get("Background").setScale(			*m_Scale	);
	m_RectangleShapes->get("ButtonPlay").setScale(			*m_Scale	);
	m_RectangleShapes->get("ButtonGameMode").setScale(		*m_Scale	);
	m_RectangleShapes->get("ButtonScreenMode").setScale(	*m_Scale	);
	m_RectangleShapes->get("ButtonResolution").setScale(	*m_Scale	);
	m_RectangleShapes->get("ButtonQuit").setScale(			*m_Scale	);
	m_RectangleShapes->get("MessageBanner").setScale(		*m_Scale	);
	m_RectangleShapes->get("SplashScreen").setScale(		*m_Scale	);
	m_RectangleShapes->get("PlayerLeft").setScale(			*m_Scale	);
	m_RectangleShapes->get("PlayerRight").setScale(			*m_Scale	);
	m_RectangleShapes->get("PongBall").setScale(			*m_Scale	);

	m_RectangleShapes->get("Background").setPosition(		sf::Vector2f(	0						*	m_Scale->x	,	0							* m_Scale->y	)	);
	m_RectangleShapes->get("ButtonPlay").setPosition(		sf::Vector2f(	0						*	m_Scale->x	,	(313	-1)					* m_Scale->y	)	);
	m_RectangleShapes->get("ButtonGameMode").setPosition(	sf::Vector2f(	0						*	m_Scale->x	,	(343	-1)					* m_Scale->y	)	);
	m_RectangleShapes->get("ButtonScreenMode").setPosition(	sf::Vector2f(	0						*	m_Scale->x	,	(373	-1)					* m_Scale->y	)	);
	m_RectangleShapes->get("ButtonResolution").setPosition(	sf::Vector2f(	0						*	m_Scale->x	,	(403	-1)					* m_Scale->y	)	);
	m_RectangleShapes->get("ButtonQuit").setPosition(		sf::Vector2f(	0						*	m_Scale->x	,	(433	-1)					* m_Scale->y	)	);
	m_RectangleShapes->get("MessageBanner").setPosition(	sf::Vector2f(	0						*	m_Scale->x	,	303							* m_Scale->y	)	);
	m_RectangleShapes->get("SplashScreen").setPosition(		sf::Vector2f(	0						*	m_Scale->x	,	0							* m_Scale->y	)	);
	m_RectangleShapes->get("PlayerLeft").setPosition(		sf::Vector2f(	50						*	m_Scale->x	,	(m_Resolution->y	/ 2)	* m_Scale->y	)	);
	m_RectangleShapes->get("PlayerRight").setPosition(		sf::Vector2f(	1230					*	m_Scale->x	,	(m_Resolution->y	/ 2)	* m_Scale->y	)	);
	m_RectangleShapes->get("PongBall").setPosition(			sf::Vector2f(	(m_Resolution->x / 2)	*	m_Scale->x	,	(m_Resolution->y	/ 2)	* m_Scale->y	)	);

	m_RectangleShapes->get("Background").setFillColor(			sf::Color::White	);
	m_RectangleShapes->get("ButtonPlay").setFillColor(			sf::Color::Black	);
	m_RectangleShapes->get("ButtonGameMode").setFillColor(		sf::Color::Black	);
	m_RectangleShapes->get("ButtonScreenMode").setFillColor(	sf::Color::Black	);
	m_RectangleShapes->get("ButtonResolution").setFillColor(	sf::Color::Black	);
	m_RectangleShapes->get("ButtonQuit").setFillColor(			sf::Color::Black	);
	m_RectangleShapes->get("MessageBanner").setFillColor(		sf::Color::Black	);
	m_RectangleShapes->get("SplashScreen").setFillColor(		sf::Color::Black	);
	m_RectangleShapes->get("PlayerLeft").setFillColor(			sf::Color::White	);
	m_RectangleShapes->get("PlayerRight").setFillColor(			sf::Color::White	);
	m_RectangleShapes->get("PongBall").setFillColor(			sf::Color::White	);

	m_RectangleShapes->get("Background").setOpacity(		0	);
	m_RectangleShapes->get("ButtonPlay").setOpacity(		0	);
	m_RectangleShapes->get("ButtonGameMode").setOpacity(	0	);
	m_RectangleShapes->get("ButtonScreenMode").setOpacity(	0	);
	m_RectangleShapes->get("ButtonResolution").setOpacity(	0	);
	m_RectangleShapes->get("ButtonQuit").setOpacity(		0	);
	m_RectangleShapes->get("MessageBanner").setOpacity(		0	);
	m_RectangleShapes->get("SplashScreen").setOpacity(		250	);
	m_RectangleShapes->get("PlayerLeft").setOpacity(		0	);
	m_RectangleShapes->get("PlayerRight").setOpacity(		0	);
	m_RectangleShapes->get("PongBall").setOpacity(			0	);

	m_RectangleShapes->get("Background").setSpeed(			sf::Vector2f(		0.0f	,	0.0f	)	);
	m_RectangleShapes->get("ButtonPlay").setSpeed(			sf::Vector2f(		0.0f	,	0.0f	)	);
	m_RectangleShapes->get("ButtonGameMode").setSpeed(		sf::Vector2f(		0.0f	,	0.0f	)	);
	m_RectangleShapes->get("ButtonScreenMode").setSpeed(	sf::Vector2f(		0.0f	,	0.0f	)	);
	m_RectangleShapes->get("ButtonResolution").setSpeed(	sf::Vector2f(		0.0f	,	0.0f	)	);
	m_RectangleShapes->get("ButtonQuit").setSpeed(			sf::Vector2f(		0.0f	,	0.0f	)	);
	m_RectangleShapes->get("MessageBanner").setSpeed(		sf::Vector2f(		0.0f	,	0.0f	)	);
	m_RectangleShapes->get("SplashScreen").setSpeed(		sf::Vector2f(		0.0f	,	0.0f	)	);
	m_RectangleShapes->get("PlayerLeft").setSpeed(			sf::Vector2f(		3.0f	,	3.0f	)	);
	m_RectangleShapes->get("PlayerRight").setSpeed(			sf::Vector2f(		3.0f	,	3.0f	)	);
	m_RectangleShapes->get("PongBall").setSpeed(			sf::Vector2f(		3.0f	,	3.0f	)	);

	m_RectangleShapes->get("Background").setRenderEnabled(			true	);
	m_RectangleShapes->get("ButtonPlay").setRenderEnabled(			true	);
	m_RectangleShapes->get("ButtonGameMode").setRenderEnabled(		true	);
	m_RectangleShapes->get("ButtonScreenMode").setRenderEnabled(	true	);
	m_RectangleShapes->get("ButtonResolution").setRenderEnabled(	true	);
	m_RectangleShapes->get("ButtonQuit").setRenderEnabled(			true	);
	m_RectangleShapes->get("MessageBanner").setRenderEnabled(		false	);
	m_RectangleShapes->get("SplashScreen").setRenderEnabled(		true	);
	m_RectangleShapes->get("PlayerLeft").setRenderEnabled(			true	);
	m_RectangleShapes->get("PlayerRight").setRenderEnabled(			true	);
	m_RectangleShapes->get("PongBall").setRenderEnabled(			true	);

	m_RectangleShapes->get("Background").setRenderLayer(		1	);
	m_RectangleShapes->get("ButtonPlay").setRenderLayer(		2	);
	m_RectangleShapes->get("ButtonGameMode").setRenderLayer(	2	);
	m_RectangleShapes->get("ButtonScreenMode").setRenderLayer(	2	);
	m_RectangleShapes->get("ButtonResolution").setRenderLayer(	2	);
	m_RectangleShapes->get("ButtonQuit").setRenderLayer(		2	);
	m_RectangleShapes->get("MessageBanner").setRenderLayer(		2	);
	m_RectangleShapes->get("SplashScreen").setRenderLayer(		4	);
	m_RectangleShapes->get("PlayerLeft").setRenderLayer(		2	);
	m_RectangleShapes->get("PlayerRight").setRenderLayer(		2	);
	m_RectangleShapes->get("PongBall").setRenderLayer(			2	);
}																																						