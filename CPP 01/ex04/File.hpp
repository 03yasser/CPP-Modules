/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:49:30 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/20 09:32:01 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>
#include <iostream>

class	File
{
	private:
		std::string		_File_name;
		std::string		_S1;
		std::string		_S2;
		std::ifstream	ifile;
		std::ofstream	ofile;
	public:
		File(std::string File_name, std::string S1, std::string S2);
		bool	oc_files();
		void	close_files();
		bool	replace_content();
};

#endif