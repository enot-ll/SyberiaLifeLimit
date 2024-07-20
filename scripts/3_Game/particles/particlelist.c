modded class ParticleList
{
    // CONTAMINATED AREAS

	static const int ASH = RegisterSybParticle("ash");
    static const int FOG = RegisterSybParticle("fog");

    static int RegisterSybParticle(string file_name)
	{
		return RegisterParticle(GetPathToSybParticles(), file_name);
	}

	static string GetPathToSybParticles()
	{
		return "SyberiaScripts/particles/";
	}

}