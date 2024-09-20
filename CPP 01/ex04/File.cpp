/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:49:22 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/20 09:30:02 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string File_name, std::string S1, std::string S2) : _File_name(File_name), _S1(S1) , _S2(S2) {}

bool	File::oc_files()
{
	std::string	ofile_name = _File_name;
	ifile.open(_File_name);
	if (!ifile.is_open())
	{
		std::cout << "The in file is not opened." << std::endl;
		return (false);
	}
	ofile_name.append(".replace");
	ofile.open(ofile_name);
	if (!ofile.is_open())
	{
		std::cout << "The out file is not opened." << std::endl;
		return (false);
	}
	return (true);
}

void	File::close_files()
{
	ifile.close();
	ofile.close();
}


bool	File::replace_content()
{
	std::string	line;

	if (!ifile.is_open())
	{
		std::cout << "The file is not opened." << std::endl;
		return (false);
	}
	while (std::getline(ifile, line))
	{
		std::size_t	index = 0;
		std::string	result;
		while ((index = line.find(_S1, index)) != line.npos)
		{
			result.clear();
			result += line.substr(0, index);
			result += _S2;
			result += line.substr(index + _S1.size(), line.size());
			index += _S1.size();
			line = result;
		}
		ofile << line << std::endl;
	}
	return (true);
}